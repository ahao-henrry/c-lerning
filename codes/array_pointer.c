#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int a[3][5];
    int i, j, k = 0;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            a[i][j] = k++;
        }
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }

    int (*pArray)[5];
    pArray = a;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("a[%d][%d] = %d\n", i, j, *(*(pArray+i) +j ));
        }
    }

    printf("pArray = %p, &a[0] = %p\n", pArray, &a[0]);
    printf("pArray+1 = %p, &a[1] = %p\n", pArray+1, &a[1]);

    return 0;
}
