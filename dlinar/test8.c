#include <stdio.h>
#include "dlinar.h"
#include "testing.h"

char* test_gcd_ll_1(){
    LL  A = {1, 0x4FE8},\
        B = {1, 0x1462},\
        C = {0},\
        D = {1, 0x0002};
    gcd_ll(A,B,C);
    mu_assert("Error in function gcd_ll, test #1.", comp_ll(C,D) == 3);
}

char* test_gcd_ll_2(){
    LL  A = {2, 0x1643, 0x0015},\
        B = {2, 0x8A19, 0x000A},\
        C = {0},\
        D = {1, 0x0017};
    gcd_ll(A,B,C);
    mu_assert("Error in function gcd_ll, test #2.", comp_ll(C,D) == 3);
}

char* test_gcd_ll_3(){
    LL  A = {1, 0xFACE},\
        B = {1, 0xFACE},\
        C = {0},\
        D = {1, 0xFACE};
    gcd_ll(A,B,C);
    mu_assert("Error in function gcd_ll, test #3.", comp_ll(C,D) == 3);
}
char* test_gcd_ll_4(){
    LL  A = {1, 0x0067},\
        B = {1, 0xFACE},\
        C = {0},\
        D = {1, 0x0001};
    gcd_ll(A,B,C);
    mu_assert("Error in function gcd_ll, test #4.", comp_ll(C,D) == 3);
}
char* test_gcd_ll_5(){
    LL  A = {2, 0x0000, 0x0001},\
        B = {1, 0x0300},\
        C = {0},\
        D = {1, 0x0100};
    gcd_ll(A,B,C);
    mu_assert("Error in function gcd_ll, test #5.", comp_ll(C,D) == 3);
}
