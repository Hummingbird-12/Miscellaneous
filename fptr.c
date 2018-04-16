#include <stdio.h>
#include <stdlib.h>

void* data;

void printInt(void* n) {
    printf("Here's the integer: %d\n", *(int*)n);
}

void printFloat(void* n) {
    printf("Here's the floating point: %lf\n", *(double*)n);
}

void printChar(void* c) {
    printf("Here's the character: %c\n", *(char*)c);
}

void printAny(void (func)(void*), void* d) {
    (func)(d);
}

int main() {
    int num = 100;
    double fp = 3.14;
    char c = 'Z';

    data = malloc(sizeof(int));
    *(int*)data = num;
    printAny(printInt, data);
    free(data);

    data = malloc(sizeof(double));
    *(double*)data = fp;
    printAny(printFloat, data);
    free(data);

    data = malloc(sizeof(char));
    *(char*)data = c;
    printAny(printChar, data);
    free(data);

    return 0;
}
