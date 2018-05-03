#include <stdio.h>

int main() {
    int i;
    double f = 3.14;

    for(i = 1; i <= 10; i++)
        printf("%.*lf\n", i, f);
    puts("");
    return 0;
}
