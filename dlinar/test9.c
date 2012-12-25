#include <stdio.h>
#include "dlinar.h"
#include "testing.h"

char* test_barrett_ll_1(){
    LL  A = {4, 0x4444, 0x3333, 0x2222, 0x1111},\
        N = {2, 0xdaff, 0xaffe},\
        C = {0},\
        D = {2, 0x8bf8, 0x5883},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #1.", comp_ll(C,D) == 3);
}

char* test_barrett_ll_2(){
    LL A = {2, 0x0001, 0x0011},\
        N = {2, 0x0003, 0x0012},\
        C = {0},\
        D = {2, 0x0001, 0x0011},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #2.", comp_ll(C,D)==3);
}
char* test_barrett_ll_3(){
    LL A = {2, 0xFACE, 0x0021},\
        N = {2, 0xFACE, 0x0011},\
        C = {0},\
        D = {2, 0x0000, 0x0010},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #3.", comp_ll(C,D)==3);
}
char* test_barrett_ll_4(){
    LL A = {1, 0x0014},\
        N = {1, 0x0006},\
        C = {0},\
        D = {1, 0x0002},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #4.", comp_ll(C,D)==3);
}
char* test_barrett_ll_5(){
    LL A = {2, 0xaaaa, 0xaaaa},\
        N = {1, 0x000a},\
        C = {0},\
        D = {0},\
        mu = {0};
//    print_l(N);
finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #5.", comp_ll(C,D)==3);
}
char* test_barrett_ll_6(){
    LL A = {2, 0x0005, 0x0100},\
        N = {1, 0x1000},\
        C = {0},\
        D = {1 ,0x0005},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #6.", comp_ll(C,D)==3);
}
char* test_barrett_ll_7(){
    LL A = {3, 0x0001, 0x5322, 0xACDC},\
        N = {1, 0xFFFF},\
        C = {0},\
        D = {0},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #7.", comp_ll(C,D)==3);
}
char* test_barrett_ll_8(){
    LL A = {2, 0xFFF5, 0x000F},\
        N = {1, 0x0010},\
        C = {0},\
        D = {1, 0x0005},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #8.", comp_ll(C,D)==3);
}
/*
char* test_barrett_ll_9(){
    LL A = {4, 0xAAAA, 0xAAAA, 0xAAAA, 0x00AA},\
        N = {1, 0xAAAA},\
        C = {0},\
        D = {1, 0x00AA},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    print_l_mas(C);
    mu_assert("Error in function barrett_ll, test #9.", comp_ll(C,D)==3);
}*/
char* test_barrett_ll_10(){
    LL A = {4, 0xD82E, 0x70A3, 0xD39F, 0x7D27},\
        N = {2, 0xBBBB, 0xBBBB},\
        C = {0},\
        D = {2, 0xDF01, 0x20FE},\
        mu = {0};
//    print_l(N);
    finding_of_mu(N,mu);
    barrett_ll(A,N,mu,C);
    mu_assert("Error in function barrett_ll, test #10.", comp_ll(C,D)==3);
}
