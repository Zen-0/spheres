#include <stdio.h>
#include "dlinar.h"
#include "testing.h"



char* test_itol_1(){
    int a=1;
    LL A = {1, 0x0001},\
       B;
    itol(B,a);
    mu_assert("Error in function itol, test #1.", comp_ll(A,B) == 3);
}
char* test_itol_2(){
    int a=0xFADEC;
    LL A = {2, 0xADEC, 0x000F},\
       B;
    itol(B,a);
    mu_assert("Error in function itol, test #2.", comp_ll(A,B) == 3);
}
char* test_itol_3(){
    int a=0;
    LL A = {1, 0x0000},\
       B;
    itol(B,a);
    mu_assert("Error in function itol, test #3.", comp_ll(A,B) == 3);
}
