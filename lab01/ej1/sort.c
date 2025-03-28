#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    int j = i;
    while (j > 0 && goes_before(a[j], a[j-1])) {
        swap(a, j-1, j);
        j=j-1;
        array_dump(a, length);
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
        assert(array_is_sorted(a, i));
    }
}

//gcc -Wall -Wextra -pedantic -std=c99 -c array_helpers.c sort.c sort_helpers.c main.c 
//gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o sort.o sort_helpers.o main.o -o sorter
//./sorter ../input/unsorted-100.in