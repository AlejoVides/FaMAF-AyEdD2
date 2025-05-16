#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();
    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
      { {8}, 1, true },
      { {2, 7}, 2, true},
      { {7, 2}, 2, true},
      { {6, 5, 8}, 3, false},
      { {5, 6, 5}, 3, true},
      { {3, 6, 9, 12, 11}, 5, true},
      { {3, 6, 9, 8, 11}, 5, false},
      { {3, 2, 4, 5, 6, 8}, 6, false},
      { {-1, 0, -1, -2, -3, -4}, 6, true},
      { {1, 2, 3, 4, 5, 4, 3, 2, 1, 2}, 10, false}
    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i = 0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);
        result = tiene_cima(tests[i].a, tests[i].length);
        if (result != tests[i].result) printf("FAILED\n");
        else printf("OK\n");
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 },
        { {2, 7}, 2, 1 },
        { {5, 6, 5}, 3, 1 },
        { {3, 6, 9, 12, 11}, 5, 3 },
        { {-1, 0, -1, -2, -3, -4}, 6, 1 },
        { {4, 7, 50, 6, 5}, 5, 2 },
        { {1, 3, 5, 7, 6, 4, 2}, 7, 3 },
        { {6, 7, 8, 9, 10}, 5, 4 },
        { {4, 3, 2, 1}, 4, 0 },
        { {0}, 1, 0 }
    };
    
    int result;
    printf("TESTING cima\n");
    for (int i = 0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);
        result = cima(tests[i].a, tests[i].length);
        if (result == tests[i].result) printf("OK\n");
        else printf("FAILED. got %d expected %d\n", result, tests[i].result);
    }
}