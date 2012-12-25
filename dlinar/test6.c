#include <stdio.h>
#include "dlinar.h"
#include "testing.h"

char* test_div_ll_1(){
    LL A = {1, 0x0001},\
        B = {0},\
        Res = {0},\
        Ost = {0};
    mu_assert("Error in function div_ll, test #1.", div_ll(A,B,Res,Ost) == -1);
}
char* test_div_ll_2(){
    LL A = {2, 0x0001, 0x0011},\
        B = {2, 0x0003, 0x0012},\
        Res = {0},\
        Ost = {0},\
        eRes = {0},\
        eOst = {2, 0x0001, 0x0011};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #2.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_3(){
    LL A = {2, 0xFACE, 0x0011},\
        B = {2, 0xFACE, 0x0011},\
        Res = {0},\
        Ost = {0},\
        eRes = {1, 0x0001},\
        eOst = {0};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #3.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_4(){
    LL A = {1, 0x0014},\
        B = {1, 0x0006},\
        Res = {0},\
        Ost = {0},\
        eRes = {1, 0x0003},\
        eOst = {1, 0x0002};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #4.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_5(){
    LL A = {2, 0xaaaa, 0xaaaa},\
        B = {1, 0x000a},\
        Res = {0},\
        Ost = {0},\
        eRes = {2, 0x1111, 0x1111},\
        eOst = {0};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #5.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_6(){
    LL A = {2, 0x0005, 0x0100},\
        B = {1, 0x1000},\
        Res = {0},\
        Ost = {0},\
        eRes = {1, 0x1000},\
        eOst = {1 ,0x0005};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #6.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_7(){
    LL A = {3, 0x0001, 0x5322, 0xACDC},\
        B = {1, 0xFFFF},\
        Res = {0},\
        Ost = {0},\
        eRes = {2, 0xFFFF, 0xACDC},\
        eOst = {0};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #7.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_8(){
    LL A = {2, 0xFFF5, 0x000F},\
        B = {1, 0x0010},\
        Res = {0},\
        Ost = {0},\
        eRes = {1, 0xFFFF},\
        eOst = {1, 0x0005};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #8.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_9(){
    LL A = {4, 0xEEEE, 0xDDDD, 0xAAAA, 0xFFFF},\
        B = {4, 0x4444, 0x3333, 0x2222, 0x0111},\
        Res = {0},\
        Ost = {0},\
        eRes = {1, 0x00EF},\
        eOst = {4, 0x3372, 0x1101, 0xCCBD, 0x0100};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #9.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_10(){
    LL A = {8, 0xA000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0AAA},\
        B = {1, 0xAAAA},\
        Res = {0},\
        Ost = {0},\
        eRes = {7, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000},\
        eOst = {0};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #10.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
char* test_div_ll_11(){
    LL A = {4, 0xD82E, 0x70A3, 0xD39F, 0x7D27},\
        B = {2, 0xBBBB, 0xBBBB},\
        Res = {0},\
        Ost = {0},\
        eRes = {2, 0xAC37, 0xAAAA},\
        eOst = {2, 0xDF01, 0x20FE};
    div_ll(A,B,Res,Ost);
    mu_assert("Error in function div_ll, test #11.", comp_ll(Res,eRes)==3 && comp_ll(Ost,eOst)==3);
}
