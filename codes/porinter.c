#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[20] = "aaaa";
    char buf2[] = "bbbb";
    char *p = "aaaa";
    char *p1 = (char *)malloc(100);
    strcpy(p1, "126836");

    printf("buf = %X, p = %X\n", buf, p);

    return 0;
}
