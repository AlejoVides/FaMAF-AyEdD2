#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 1

int main() {
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
    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);
        result = cima_log(tests[i].a, tests[i].length);
        if (result == tests[i].result) printf("OK\n");
        else printf("FAILED. got %d expected %d\n", result, tests[i].result);
    }
    return 0;
}