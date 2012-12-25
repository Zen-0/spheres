#include <stdio.h>
#include <unistd.h>
#include "dlinar.h"
#include "testing.h"



int tests_run;
int tests_not_passed = 0;
int units[max_units];
int foo = 71;
int bar = 51;
 static char * test_foo() {
     mu_assert("error, foo != 7", foo == 7);
 }

 static char * test_bar() {
     mu_assert("error, bar != 5", bar == 5);
 }

void all_tests() {
     if(units[0]){
        printf("Unit 0 run...\n");
        mu_run_test(test_foo);
        mu_run_test(test_bar);
     }
     if(units[1]){
        printf("Unit 1 run...\n");
        mu_run_test(test_comp_1);
        mu_run_test(test_comp_2);
        mu_run_test(test_comp_3);
        mu_run_test(test_comp_4);
        mu_run_test(test_comp_5);
        mu_run_test(test_comp_6);
        mu_run_test(test_comp_7);
        mu_run_test(test_assign_ll_1);
        mu_run_test(test_assign_ll_2);
     }
     if(units[2]){
        printf("Unit 2 run...\n");
        mu_run_test(test_itol_1);
        mu_run_test(test_itol_2);
        mu_run_test(test_itol_3);
     }
     if(units[3]){
        printf("Unit 3 run...\n");
        mu_run_test(test_add_ll_1);
        mu_run_test(test_add_ll_2);
        mu_run_test(test_add_ll_3);
        mu_run_test(test_add_ll_4);
        mu_run_test(test_add_ll_5);
        mu_run_test(test_add_ll_6);
        mu_run_test(test_add_ll_7);
     }
     if(units[4]){
        printf("Unit 4 run...\n");
        mu_run_test(test_sub_ll_1);
        mu_run_test(test_sub_ll_2);
        mu_run_test(test_sub_ll_3);
        mu_run_test(test_sub_ll_4);
        mu_run_test(test_sub_ll_5);
        mu_run_test(test_sub_ll_6);
        mu_run_test(test_sub_ll_7);
        mu_run_test(test_sub_ll_8);
        mu_run_test(test_sub_ll_9);
     }
     if(units[5]){
        printf("Unit 5 run...\n");
        mu_run_test(test_smul_ls_1);
        mu_run_test(test_smul_ls_2);
        mu_run_test(test_smul_ls_3);

        mu_run_test(test_smul_ll_1);
        mu_run_test(test_smul_ll_2);
        mu_run_test(test_smul_ll_3);
        mu_run_test(test_smul_ll_4);
        mu_run_test(test_smul_ll_5);
        mu_run_test(test_smul_ll_6);
        mu_run_test(test_smul_ll_7);
     }
     if(units[6]){
        printf("Unit 6 run...\n");
        mu_run_test(test_div_ll_1);
        mu_run_test(test_div_ll_2);
        mu_run_test(test_div_ll_3);
        mu_run_test(test_div_ll_4);
        mu_run_test(test_div_ll_5);
        mu_run_test(test_div_ll_6);
        mu_run_test(test_div_ll_7);
        mu_run_test(test_div_ll_8);
        mu_run_test(test_div_ll_9);
     }
     if(units[7]){
        printf("Unit 7 run...\n");
        mu_run_test(test_shl_l_1);
        mu_run_test(test_shl_l_2);
        mu_run_test(test_shl_l_3);
        mu_run_test(test_shl_l_4);
        mu_run_test(test_shl_l_5);
        mu_run_test(test_shr_l_1);
        mu_run_test(test_shr_l_2);
        mu_run_test(test_shr_l_3);
        mu_run_test(test_shr_l_4);
        mu_run_test(test_shr_l_5);
     }
     if(units[8]){
        printf("Unit 8 run...\n");
        mu_run_test(test_gcd_ll_1);
        mu_run_test(test_gcd_ll_2);
        mu_run_test(test_gcd_ll_3);
        mu_run_test(test_gcd_ll_4);
        mu_run_test(test_gcd_ll_5);

     }
     if(units[9]){
        printf("Unit 9 run...\n");
        mu_run_test(test_barrett_ll_1);
        mu_run_test(test_barrett_ll_2);
        mu_run_test(test_barrett_ll_3);
        mu_run_test(test_barrett_ll_4);
        mu_run_test(test_barrett_ll_5);
        mu_run_test(test_barrett_ll_6);
        mu_run_test(test_barrett_ll_7);
        mu_run_test(test_barrett_ll_8);
 //       mu_run_test(test_barrett_ll_9);
        mu_run_test(test_barrett_ll_10);

     }
     return;
 }

int tests(int argc, char *argv[]){
    int i;
    for(i=0;i<max_units;i++)
        units[i]=FALSE;
	int rez = 0,arg;

    int correctArgs = FALSE;
	while ( (rez = getopt(argc,argv,"ht:a")) != -1){
	    correctArgs = TRUE;
	    switch (rez){
        case 'h': printf("Please, input argument '-t' with parametrs to run the appropriate test unit:\n\
            0 - test of testing =);\n\
            1 - assign and comparison of long numbers\n\
            2 - int to long;\n\
            3 - addition;\n\
            4 - subtraction;\n\
            5 - simple multiplication.\n\
            6 - division\n\
            7 - binary shift\n\
            8 - gratest common dividor\n\
            9 - Barrett reduction\n\
        Or use argument '-a' to run all units except 0.\n");return 0;
		case 't': { arg = atoi(optarg);
                    //printf("found argument \"t = %d\".\n",arg);
                    if (arg<max_units){
                        units[arg] = TRUE;
                        }
                    else {printf("%d is wrong parameter for t.\nUse -h for help.\n", arg);
                          return 0;}
                    break;}
        case 'a':  {for(i=1;i<max_units;i++)
                        units[i] = TRUE;
                    break;}
		case '?': correctArgs = FALSE; break;
        };
	};
	if(!correctArgs){
        printf("Use -h for help.\n");
        return 0;
    }
    all_tests();
    printf("Tests run: %d\n", tests_run);
    if(!tests_not_passed)
        printf("ALL TESTS PASSED\n");
    else
       printf("Failed:    %d\n", tests_not_passed);
    return 0;

};
