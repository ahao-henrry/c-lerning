#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sub_fun(char **p1, int * len1, char **p2, int *len2);

int main()
{
    char *p1 = NULL;
    int len1 = 0;
    char *p2 = NULL;
    int len2 = 0;

//p1 = 0xaa;
//len1 = 12;
//p2 = 0x1234;
//len2 = 13;
//printf("p1 = %s, len1 = %d, p2 = %s, len2 = %d\n", p1, len1, p2, len2);

    sub_fun(&p1, &len1, &p2, &len2);

    printf("p1 = %s, len1 = %d, p2 = %s, len2 = %d\n", p1, len1, p2, len2);

    return 0;
}

void sub_fun(char **p1, int *len1, char **p2, int *len2)
{
    char *temp1 = (char *)malloc(100);
    char *temp2 = (char *)malloc(100);
    strcpy(temp1, "name: ahao");
    strcpy(temp2, "age: 18");

    *p1 = temp1;
    *p2 = temp2;

    *len1 = 120;
    *len2 = 140;
}
