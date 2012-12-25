#include <stdio.h>
#include "dlinar.h"
#include "testing.h"

char* test_shl_l_1(){
    LL A = {1, 0x0010},\
        C = {1, 0x0800};
    int b = 7;
    shl_l(A,b);
    mu_assert("Error in function shl_l, test #1.", comp_ll(A,C) == 3);
}

char* test_shl_l_2(){
    LL A = {1, 0xFFFF},\
        C = {2, 0xFFFE, 0x0001};
    int b = 1;
    shl_l(A,b);
    mu_assert("Error in function shl_l, test #2.", comp_ll(A,C) == 3);
}

char* test_shl_l_3(){
    LL A = {1, 0xFACE},\
        C = {3, 0x0000, 0x0000, 0xFACE};
    int b = 32;
    shl_l(A,b);

    mu_assert("Error in function shl_l, test #3.", comp_ll(A,C) == 3);
}

char* test_shl_l_4(){
    LL A = {3, 0x7ACE, 0xFFFF, 0xFFFE},\
        C = {4, 0xF59C, 0xFFFE, 0xFFFD, 0x0001};
    int b = 1;
    shl_l(A,b);
    mu_assert("Error in function shl_l, test #4.", comp_ll(A,C) == 3);
}
char* test_shl_l_5(){
    LL A = {2, 0xFFFF, 0x000A},\
        C = {4, 0x0000, 0x0000, 0xFFF8, 0x0057};
    int b = 35;
    shl_l(A,b);

    mu_assert("Error in function shl_l, test #5.", comp_ll(A,C) == 3);
}

char* test_shr_l_1(){
    LL A = {1, 0x0010},\
        C = {1, 0x0800};
    int b = 7;
    shr_l(C,b);
    mu_assert("Error in function shr_l, test #1.", comp_ll(A,C) == 3);
}

char* test_shr_l_2(){
    LL A = {1, 0xFFFF},\
        C = {2, 0xFFFE, 0x0001};
    int b = 1;
    shr_l(C,b);
    mu_assert("Error in function shr_l, test #2.", comp_ll(A,C) == 3);
}

char* test_shr_l_3(){
    LL A = {1, 0xFACE},\
        C = {3, 0x0000, 0x0000, 0xFACE};
    int b = 32;
    shr_l(C,b);
    mu_assert("Error in function shr_l, test #3.", comp_ll(A,C) == 3);
}

char* test_shr_l_4(){
    LL A = {3, 0x7ACE, 0xFFFF, 0xFFFE},\
        C = {4, 0xF59C, 0xFFFE, 0xFFFD, 0x0001};
    int b = 1;
    shr_l(C,b);
    mu_assert("Error in function shr_l, test #4.", comp_ll(A,C) == 3);
}

char* test_shr_l_5(){
    LL A = {2, 0xFFFF, 0x000A},\
        C = {4, 0x0000, 0x0000, 0xFFF8, 0x0057};
    int b = 35;
    shr_l(C,b);
    mu_assert("Error in function shr_l, test #5.", comp_ll(A,C) == 3);
}

