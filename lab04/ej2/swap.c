#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = 0;
    t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int x = 6, y = 4;
    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);
    return EXIT_SUCCESS;
}