#include <stdio.h>
#include "dlinar.h"
#include "testing.h"

char* test_smul_ls_1(){
    LL A = {1, 0x1000},\
        C = {0},\
        D = {2, 0x0000, 0x0400};
    USHORT b = 0x4000;
    smul_ls(A,b,C);
    smul_ls(A,b,C);
    smul_ls(A,b,C);
    mu_assert("Error in function smul_ls, test #1.", comp_ll(C,D) == 3);
}
char* test_smul_ls_2(){
    LL A = {2, 0xFFFF, 0xACDC},\
        C = {0},\
        D = {3, 0x0001, 0x5322, 0xACDC};
    USHORT b = 0xFFFF;
    smul_ls(A,b,C);
    mu_assert("Error in function smul_ls, test #2.", comp_ll(C,D) == 3);
}
char* test_smul_ls_3(){
    LL A = {1, 0x000a},\
        C = {0},\
        D = {2, 0x0000, 0x0005};
    USHORT b = 0x8000;
    smul_ls(A,b,C);
    mu_assert("Error in function smul_ls, test #3.", comp_ll(C,D) == 3);
}

char* test_smul_ll_1(){
    LL A = {1, 0x0001},\
        B = {1, 0x0003},\
        C = {0},\
        D = {1, 0x0003};
    smul_ll(A,B,C);
    mu_assert("Error in function smul_ll, test #1.", comp_ll(C,D) == 3);
}
char* test_smul_ll_2(){
    LL A = {1, 0xFFFF},\
        B = {1, 0x0010},\
        C = {0},\
        D = {2, 0xFFF0, 0x000F};
    smul_ll(A,B,C);
    mu_assert("Error in function smul_ll, test #2.", comp_ll(C,D) == 3);
}
char* test_smul_ll_3(){
    LL A = {1, 0xABCD},\
        B = {1, 0x789A},\
        C = {0},\
        D = {2, 0x7152, 0x50EF};
    smul_ll(A,B,C);
    mu_assert("Error in function smul_ll, test #3.", comp_ll(C,D) == 3);
}
char* test_smul_ll_4(){
    LL A = {2, 0xAAAA, 0xBBBB},\
        B = {2, 0xBBBB, 0xAAAA},\
        C = {0},\
        D = {4, 0xD82E, 0x70A3, 0xD39F, 0x7D27};
    smul_ll(A,B,C);

    mu_assert("Error in function smul_ll, test #4.", comp_ll(C,D) == 3);
}
char* test_smul_ll_5(){
    LL A = {7, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA},\
        B = {1, 0x1000},\
        C = {0},\
        D = {8, 0xA000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0AAA};
    smul_ll(A,B,C);
    mu_assert("Error in function smul_ll, test #5.", comp_ll(C,D) == 3);
}
char* test_smul_ll_6(){
    LL A = {2, 0x0001, 0xACDC},\
        B = { 0 },\
        C = { 0 },\
        D = { 0 };
    smul_ll(A,B,C);
    mu_assert("Error in function smul_ll, test #6.", comp_ll(C,D) == 3);
}
char* test_smul_ll_7(){
    LL A = {1, 0x0001},\
        B = {2, 0x0000, 0xACDC},\
        C = {1, 0x8989},\
        D = {2, 0x0000, 0xACDC};
    smul_ll(A,B,C);
    mu_assert("Error in function smul_ll, test #7.", comp_ll(C,D) == 3);
}
