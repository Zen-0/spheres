//---MinUnit testing framework =) ---
#define mu_assert(message, test) do { if (!(test)) return message; return 0; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++;  \
                               if (message) { printf("%s\n", message); \
                                             tests_not_passed++;}  } while (0)
//---_______---
#define max_units 10
