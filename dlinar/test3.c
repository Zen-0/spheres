#include <stdio.h>
#include "dlinar.h"
#include "testing.h"



char* test_add_ll_1(){
    LL A = {1, 0x0001},\
        B = {1, 0x0002},\
        C = {0},\
        D = {1, 0x0003};
    add_ll(A,B,C);
    mu_assert("Error in function add_ll, test #1.", comp_ll(C,D) == 3);
}
char* test_add_ll_2(){
    LL A = {1, 0x0001},\
        B = {2, 0xFFFF, 0x0002},\
        C = {0},\
        D = {2, 0x0000, 0x0003};
    add_ll(A,B,C);
    mu_assert("Error in function add_ll, test #2.", comp_ll(C,D) == 3);
}
char* test_add_ll_3(){
    LL A = {2, 0x00FF, 0xFFFF},\
        B = {2, 0x0F01, 0x0002},\
        C = {0},\
        D = {3, 0x1000, 0x0001, 0x0001};
    add_ll(A,B,C);
    mu_assert("Error in function add_ll, test #3.", comp_ll(C,D) == 3);
}
char* test_add_ll_4(){
    LL A = {6, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x1000},\
        B = {0},\
        C = {0},\
        D = {6, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x1000};
    add_ll(A,B,C);
    mu_assert("Error in function add_ll, test #4.", comp_ll(C,D) == 3);
}
char* test_add_ll_5(){
    LL A = {1, 0x0001},\
        B = {7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0XFFFF, 0xFFFF, 0xFFFF},\
        C = {0},\
        D = {8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 ,0x0000, 0x0000, 0x0001};
    add_ll(A,B,C);
    int i;
    mu_assert("Error in function add_ll, test #5.", comp_ll(C,D) == 3);
}
char* test_add_ll_6(){
    LL A = {2, 0xFFFA, 0xFFFF},\
        B = {2, 0xFFF6, 0xFFFF},\
        C = {0},\
        D = {3, 0xFFF0, 0xFFFF, 0x0001};
    add_ll(A,B,C);
    mu_assert("Error in function add_ll, test #6.", comp_ll(C,D) == 3);
}
char* test_add_ll_7(){
    LL A = {7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0XFFFF, 0xFFFF, 0xFFFF},\
        B = {7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0XFFFF, 0xFFFF, 0xFFFF},\
        C = {1, 0xFACE},\
        D = {8, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0XFFFF, 0xFFFF, 0xFFFF, 0x0001};
    add_ll(A,B,C);
    mu_assert("Error in function add_ll, test #7.", comp_ll(C,D) == 3);
}
