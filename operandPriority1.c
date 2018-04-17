#include <stdio.h>

int fun(int* par) {
    *par += 10;
    return *par + 10;
}

int main() {
    int i, j, sum1, sum2;
    i = 10;
    j = 10;
    printf("Initial values: i = %d, j = %d\n\n", i, j);
    sum1 = fun(&i) + (i / 2); // = 40
    sum2 = (j / 2) + fun(&j); // = 35
    // they are different!
    // statements in parenthesis are evaluated earlier
    // in left-to-right associativity
    printf("fun(&i) + (i / 2) = %d\n", sum1);
    printf("(j / 2) + fun(&j) = %d\n", sum2);
    printf("\nFinal values: i = %d, j = %d\n", i, j);
    return 0;
}
