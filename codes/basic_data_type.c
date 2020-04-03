#include "stdio.h"

int main() {
    int a;
    printf("type: ");
    scanf("%d", &a);
    printf("your input is : %d\n", a);

    long int b;
    printf("type l: ");
    scanf("%ld", &b);
    printf("your input is : %ld\n", b);
}
