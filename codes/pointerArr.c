/*
 *二级指针的第一种模型，指针数组
 *
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortArr(const char** arr, int size);

void printArr(const char** arr, int size);

int main(int argc, char** argv)
{
    const char* arr[] = {"cc", "bb", "dd", "aa"};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("size = %d\n", size);

    printf("pre sort:\n");
    printArr(arr, size);

    sortArr(arr, size);

    printf("post sort:\n");
    printArr(arr, size);

    return 0;
}

void printArr(const char** arr, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("arr[%d] = %s\n", i, arr[i]);
    }
}

void sortArr(const char** arr, int size)
{
    int i, j;
    char* tmp;
    for(i = 0; i < size - 1; i++)
    {
        for(j = i; j < size - 1; j++)
        {
            if(strcmp(arr[i], arr[j+1]) > 0)
            {
                tmp = arr[i];
                arr[i] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
