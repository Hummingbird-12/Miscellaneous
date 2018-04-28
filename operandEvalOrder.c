#include <stdio.h>

int a;
int b, c, d, e, f, g, h, i;

int fun() {
    a = 10;
    return 20;

}

int main() {
    a = 1;
    b = (a * 2) + fun();
    a = 1;
    c = fun() + (a * 2);
    a = 1;
    d = a * 2 + fun();
    a = 1;
    e = fun() + a * 2;
    a = 1;
    f = a + fun();
    a = 1;
    g = fun() + a;
    a = 1;
    h = a * fun();
    a = 1;
    i = fun() * a;
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = %d\n", e);
    printf("f = %d\n", f);
    printf("g = %d\n", g);
    printf("h = %d\n", h);
    printf("i = %d\n", i);
    return 0;
}
