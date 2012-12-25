#include <stdio.h>
#include "dlinar.h"
#include "testing.h"

char* test_comp_1(){
    LL A = {1, 0xFADA},\
        B = {1, 0xFADA};
    mu_assert("Error in function comp_ll, test #1.", comp_ll(A,B) == 3);
}
char* test_comp_2(){
    LL A = {1, 0xFADA},\
        B = {2, 0xFADA, 0x0001};
    mu_assert("Error in function comp_ll, test #2.", comp_ll(A,B) == 2);
}
char* test_comp_3(){
    LL A = {5, 0xFADA, 0xFADA, 0xFADA, 0xFADA, 0xFADA},\
        B = {5,0xFACF, 0xFADA, 0xFADA, 0xFADA, 0xFADA};
    mu_assert("Error in function comp_ll, test #3.", comp_ll(A,B) == 1);
}
char* test_comp_4(){
    LL A = {2, 0x0000, 0xFADA},\
        B = {1, 0xFADA};
    mu_assert("Error in function comp_ll_sh, test #4.", comp_ll_sh(A,B,1) == 3);
}
char* test_comp_5(){
    LL A = {5, 0xFADA, 0xFADA, 0xFADA, 0xFADA, 0xFADA},\
        B = {1,0xFADE};
    mu_assert("Error in function comp_ll_sh, test #5.", comp_ll_sh(A,B,4) == 2);
}
char* test_comp_6(){
    LL A = {5, 0xFADA, 0xFADA, 0xFADA, 0xFADA, 0xFADA},\
        B = {1,0xFAD9};
    mu_assert("Error in function comp_ll_sh, test #6.", comp_ll_sh(A,B,4) == 1);
}
char* test_comp_7(){
    LL A = {5, 0xFADA, 0xFADA, 0xFADA, 0xFADA, 0xFADA},\
        B = {1,0xFAD9};
    mu_assert("Error in function comp_ll_sh, test #7.", comp_ll_sh(A,B,5) == 2);
}
char* test_comp_8(){
    LL A = {5, 0xFADA, 0xFADA, 0xFADA, 0xFADA, 0xFADA},\
        B = {3, 0xFADA, 0xFADA, 0xFADA};
    mu_assert("Error in function comp_ll_sh, test #7.", comp_ll_sh(A,B,2) == 1);
}

char* test_assign_ll_1(){
    LL A = {0},\
        B = {3, 0xFADA, 0xADAC, 0x9007};
    assign_ll(A,B);
    mu_assert("Error in function assign_ll, test #1.", comp_ll(A,B) == 3);
}
char* test_assign_ll_2(){
    LL A = {2, 0xFADA, 0xCA0F},\
        B = {1, 0x9900};
    assign_ll(A,B);
    mu_assert("Error in function assign_ll, test #2.", comp_ll(A,B) == 3);
}


