#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>


int countUp(int count, ...) {
    va_list args;
    int i, sum;

    // initialize the argument list
    va_start(args, count);

    sum = 0;
    for (i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }

    // clean up
    va_end(args);
    return sum;
}


int main(void) {
    int result = 0;
    result = countUp(3, 1, 2, 3);
    printf("%d\n", result);
    return 0;
}

