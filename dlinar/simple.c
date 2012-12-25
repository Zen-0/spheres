#include <stdio.h>
#include <unistd.h>
#include "dlinar.h"

void null_l(PLL A){
    int i;
    for(i=0; i<=MAX_ORDER; i++)
        A[i] = 0;
//    A[0]=0;
}

void assign_ll(PLL A, PLL B){
 null_l(A);
 int i;
 for(i=0;i<=B[0];i++){
    A[i]=B[i];
 }
 return;
}

char* itoa(int val, int base){

	static char buf[32] = {0};

	int i = 30;

	for(; val && i ; --i, val /= base)

		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i+1];

}

/*
char[100] ltoa( PLL A, int base){
    if(A[0]==0)
        return "0x0000";
    char s[100] = "0x";
    int i;
    for(i=A[i];i>=1;--i){
        strcat (s ,  itoa(A[i],base)  );
    return s;
}

*/
void print_l(PLL A){
if(A[0]==0){
    printf("0000\n");
    return;
}
int i;
for(i=A[0]; i>0; --i){
    printf("%04x ",A[i]);
}
printf("\n");
}

void print_l_mas(PLL A){
int i;
for(i=0; i<=A[0]; ++i){
    printf("%04x ",A[i]);
}
printf("\n");
}

int comp_ll(PLL A, PLL B){
    int i;
    if ( A[0] > B[0] )
        return 1;
    if ( B[0] > A[0] )
        return 2;
    for ( i=A[0]; i>0; --i ){
        if ( A[i] > B[i] )
            return 1;
        if ( B[i] > A[i] )
            return 2;
    }
    return 3;
}

int comp_ll_sh(PLL A, PLL B, int sh){
    int i,j,l;
    if ( A[0] > B[0]+sh)
        return 1;
    if( B[0]+sh > A[0])
        return 2;
    for ( i=A[0], j=B[0]; i>0; --i, --j ){
        l = (j>0 ? B[j] : 0);
        if ( A[i] > l )
            return 1;
        if ( l > A[i] )
            return 2;
    }
    return 3;
}

void itol(PLL B, int a){
    if(a/BASE){
        B[0] = 2;
        B[1] = a%BASE;
        B[2] = a/BASE;
        return;
        }
    B[0] = 1;
    B[1] = a%BASE;
}

void add_ll(PLL A, PLL B, PLL C){
    null_l(C);
    int car=0,i,m=(A[0]>B[0] ? A[0] : B[0]),a,b,buf;
    for(i=1; i<=m || car; ++i){
        a = (i<=A[0] ? A[i] : 0);
        b = (i<=B[0] ? B[i] : 0);
        ++C[0];
        buf = a + b + car;
        C[i] = buf%BASE;
        car = (buf >= BASE);
    }
    return;
}

void sub_ll(PLL A, PLL B, PLL C){
    if(comp_ll(A,B) == 2){
            null_l(C);
            return;}
    assign_ll(C,A);
    int i, car=0,buf;
    for(i=1; i<=B[0] || car; ++i){
        buf = A[i] - car - (i<=B[0] ? B[i] : 0);
        car = buf < 0;
        if(car)
            buf += BASE;
        C[i] = buf;
    }
    while(C[0] && C[C[0]]==0)
        --C[0];
    return;
}
void sub_ll_sh(PLL A, PLL B,int sh, PLL C){
    int comp = comp_ll_sh(A,B,sh);
    if(comp == 2 || comp == 3){
            null_l(C);
            return;}
    LL Bsh;
    null_l(Bsh);
    Bsh[0] = B[0]+sh;
    int i;
    for (i=1; i<=B[0];++i)
        Bsh[i+sh]=B[i];
    sub_ll(A,Bsh,C);
}
void smul_ls(PLL A, USHORT b, PLL C){
    if(b==0){
        null_l(C);
        return;}
    assign_ll(C,A);
    int i;
    USHORT car=0;
    ULONG cur;
    for(i=1; i<=A[0] || car; ++i){
        if(i>C[0])
            ++C[0];
        cur = car + C[i]*b;
        C[i] = cur%BASE;
        car = cur/BASE;
    }
    while(C[0] && C[C[0]]==0)
        --C[0];
    return;
}

void smul_ll(PLL A, PLL B, PLL C){
    int i,j,l=0;
    USHORT car=0;
    ULONG cur;
    null_l(C);
//    C[0]=MAX_ORDER;
    for(i=1; i<=A[0]; ++i)
        for (j=1,car=0; j<=B[0] || car; ++j)
        {
            cur = C[i+j-1] + A[i] * (j<=B[0] ? B[j] : 0) +car;
            if(i+j-1>l){
                ++C[0];
                l=i+j-1;}
            C[i+j-1] = cur % BASE;
            car = cur/BASE;
        }
    while(C[0] && C[C[0]]==0)
        --C[0];
    return;
}

USHORT dichotomy (PLL Ost, PLL B, int sh){
    int down = 0, up = BASE;
    LL C;
    null_l(C);
    while(up-1>down){
        smul_ls(B, (up+down)/2, C);
        switch(comp_ll_sh(Ost,C,sh)){
            case 1:
                down = (up+down)/2;
                break;
            case 2:
                up = (up+down)/2;
                break;
            case 3:{
                up = (up+down)/2;
                down = up;
                break;
            }
        }
    }
    smul_ls(B,(up+down)/2,C);
    LL D;
    assign_ll(D,Ost);
    if(comp_ll(Ost,C)==1)
        sub_ll_sh(D,C,sh,Ost);
    else{
        sub_ll_sh(C,D,sh,Ost);}
    return (up+down)/2;
}


int div_ll(PLL A, PLL B, PLL Res, PLL Ost){
    if (B[0]==0 )
        return -1;
    switch (comp_ll(A,B)){
        case 2: {
            assign_ll(Ost,A);
            return 1;}
        case 3:{
            Res[0]=1;
            Res[1]=0x0001;
            return 1;}
        case 1:{
            assign_ll(Ost,A);
            int sh = A[0] - B[0];
            if( comp_ll_sh(A,B,sh) == 2 )
                --sh;
            Res[0] = sh+1;
            while (sh >= 0){
                Res[sh+1] = dichotomy(Ost, B, sh);
                --sh;
            }
        }
    }
};

void shl_l(PLL A, int b){
    int car=0,i,cur;
    if(b>16){
    for(i=1;i<=A[0];++i)
        A[i+b/16]=A[i];
    for(i=1;i<=b/16;++i)
        A[i]=0x0000;
    A[0]+=b/16;
    b=b%16;
    }
    if(b==0)
        return;
    for(i=1; i<=A[0]; ++i){
        cur=(A[i]<<b)/BASE;
        A[i] = (A[i]<<b)%BASE + car;
        car=cur;
    }
    if(car);
    ++A[0];
    A[A[0]]=car;
    while(A[0] && A[A[0]]==0)
        --A[0];
    return;
}

void shr_l(PLL A, int b){
    int i,car=0, cur;
    if(b>16){
        for(i=b/16+1;i<=A[0];++i)
            A[i-b/16]=A[i];
        A[0]-=b/16;
        b=b%16;
    }
    if(b==0)
        return;
    for(i=A[0];i>=1;--i){
        cur=(A[i]<<(16-b))%BASE;
        A[i]=(A[i]>>b)%BASE+car;
        car=cur;
    }
    while(A[0] && A[A[0]]==0)
        --A[0];
   return;

}

void gcd_ll(PLL A, PLL B, PLL C){
    LL U, V, R;
    assign_ll(U,A);
    assign_ll(V,B);
    if(U[0]==0){
        assign_ll(C,V);
        return;}
    if(V[0]==0){
        assign_ll(C,U);
        return;}
    int sh;
    for(sh = 0; ((U[1]|V[1])&1)==0; ++sh){
        shr_l(U,1);
        shr_l(V,1);
    }
    while((U[1]&1)==0)
        shr_l(U,1);
    do{
        while((V[1]&1)==0)
            shr_l(V,1);

        if(comp_ll(U,V)==2){
            assign_ll(R,V);
            sub_ll(R,U,V);
        }
        else{
            sub_ll(U,V,R);
            assign_ll(U,V);
            assign_ll(V,R);
        }
        shr_l(V,1);
    }while(  (V[0]!=0) || (V[0]==1 && V[1]==0));
    shl_l(U,sh);
    assign_ll(C,U);
    return;


}

