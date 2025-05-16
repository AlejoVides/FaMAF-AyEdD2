#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    x = (x >= 0) ? x : -x;
}

int main(void) {
    int a = 0, res = 0;
    absolute(a, res);
    printf("res = %d \n", res);
    return EXIT_SUCCESS;
}