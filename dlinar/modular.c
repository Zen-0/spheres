#include <stdio.h>
#include <unistd.h>
#include "dlinar.h"

void finding_of_mu(PLL N, PLL mu){
    LL d = {0},grb = {0};
    null_l(d);
    d[0]=N[0]*2+1;
    d[d[0]]=0x0001;
    div_ll(d,N,mu,grb);
}


void barrett_ll(PLL A, PLL N, PLL mu, PLL M){
    if( N[0] == 0 ){
        null_l(M);
        return;}
    assign_ll(M,A);
    if (comp_ll(A,N)==2){
        print_l(M);
        return;}
    int m = N[0];
    LL M2,q;
    assign_ll(M2,M);
    shr_l(M2,(m-1)*16);
    smul_ll(M2,mu,q);
    shr_l(q,(m+1)*16);
    LL qN;
    smul_ll(q,N,qN);
    assign_ll(M2,M);
    qN[0]=qN[0]<m+1 ? qN[0] : m+1;
    M2[0]=M2[0]<m+1 ? M2[0] : m+1;
    if(comp_ll(M2,qN)==2){
        ++M2[0];
        M2[M2[0]]=0x0001;}
    sub_ll(M2,qN,M);
    while(comp_ll(M,N)!=2){
        sub_ll(M,N,M2);
        assign_ll(M,M2);
    }
    return;
}
