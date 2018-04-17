#include <stdio.h>

int a, b;

int fun() {
    a += 10;
    return a;
}

int main() {
    a = 10;
    b = a + fun(); // = 40
    printf("With the function call on the right, ");
    printf("b is: %d\n", b);

    a = 10;
    b = fun() + a; // = 40
    printf("With the function call on the left, ");
    printf("b is: %d\n", b);

    // they are the same!
    // function call has a higher operand precedence

    return 0;
}
