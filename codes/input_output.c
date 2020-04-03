#include <stdio.h>

int main() {
    int a = 123;
    printf("%5d\n", a);
    printf("%-5d\n", a);
    printf("%05d\n", a);

    float b = 123.456f;
    printf("%09.4f\n", b);

    int c = 1 + 2 + 3 + 4;

    return 0;
}
