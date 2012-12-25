#include <stdio.h>
#include <unistd.h>
#include "dlinar.h"



int main(int argc, char *argv[])
{

    tests(argc, argv);
    LL A = {3, 0xFACE, 0xDAFF, 0xBA11};
    LL B = {2, 0x1111, 0x2222};
    LL C = {2, 0x1234, 0xFEDC};
    int n = 100;
    LL N;
    itol(N,n);
    LL K, L, M;
    add_ll(A,B,K);
    smul_ll(K,C,L);
    print_l(L);
    smul_ll(C,K,L);
    print_l(L);
    smul_ll(A,C,L);
    smul_ll(B,C,K);
    add_ll(L,K,M);
    print_l(M);
////////
    int i;
    null_l(L);
    null_l(K);
    for(i=0;i<n;++i){
        add_ll(L,A,K);
        assign_ll(L,K);
    }
    print_l(L);
    smul_ll(A,N,K);
    print_l(K);
/*    LL D = {8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001};
    LL N = {4, 0x4444, 0x3333, 0x2222, 0x0111};
    LL mu = {0};
    LL her = {0};
    div_ll(D,N,mu,her);
    printf("tra!\n\n");
    print_l(mu);*/
 //   char *s = ltoa(A,16);
    /*char s[100] = "0x";
    int i;
    for( i=A[0]; i>=1; --i){
        strcat( s, itoa(A[i],16) );
    }*/
//    printf("%s\n", ltoa(A,16));

	return 0;
}
