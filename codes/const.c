#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    const int a = 2;
    printf("a = %d\n", a);

    char* p = NULL;
    p = &a;
    *p = 3;
    printf("a = %d\n", a);


    return 0;
}
