#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr_count(char* str/*in*/, char* delimiter/*in*/, int* count/*out*/);

int split_str(char* str/*in*/, char* delimiter/*in*/, char** result_arr/*out*/);

int main(int argc, char** argv)
{
    char str[] = "hello, ahao, move, on, you, will, know";
    char* delimiter = ",";

    int size = 0;
    int ret = arr_count(str, delimiter, &size);
    if (0 != ret)
    {
        return ret;
    }

    char** arr = NULL;
    arr = (char**)malloc(sizeof(char*) * size);
    if (NULL == arr)
    {
        return -2;
    }

    ret = split_str(str, delimiter, arr);
    if (0 != ret)
    {
        printf("split_str error, code is : %d\n", ret);
        return ret;
    }

    printf("size is : %d\n", size);
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s\n", *(arr + i));
        if (NULL != *(arr + i))
        {
            free(*(arr + i));
            *(arr + i) = NULL;
        }
    }

    if (NULL != arr)
    {
        free(arr);
        arr = NULL;
    }

    return 0;
}

int split_str(char* str/*in*/, char* delimiter/*in*/, char** result_arr/*out*/)
{
    char* tmp_str = NULL;
    if (NULL == str || NULL == delimiter || NULL == result_arr)
    {
        printf("argv error");
        return -1;
    }

    tmp_str = str;
    int size = 0;

    int i = 0;
    char* p;
    char* arr;
    p = strtok(tmp_str, delimiter);
    while (1)
    {
        p = strtok(NULL, delimiter);

        arr = (char*)malloc(strlen(tmp_str) + 1);
        if (NULL == arr)
        {
            printf("arr is NULL");
            return -1;
        }
        strcpy(arr, tmp_str);
        *(result_arr + i) = arr;
        if (NULL == p)
        {
            break;
        }
        tmp_str = p;
        i++;
    }

    return 0;
}

int arr_count(char* str/*in*/, char* delimiter/*in*/, int* count/*out*/)
{
    if (NULL == str || NULL == delimiter || NULL == count)
    {
        printf("param error.");
        return -1;
    }

    char* tmp_str = NULL;
    tmp_str = (char*)malloc(strlen(str));
    if (NULL == tmp_str)
    {
        return -1;
    }
    strcpy(tmp_str, str);
    char* p;
    int i = 0;
    p = strtok(tmp_str, delimiter);
    if (NULL == p)
    {
        *count = 1;
        return 0;
    }
    i++;
    while ((p = strtok(NULL, delimiter)) != NULL)
    {
        i++;
    }

    *count = i;

    if (NULL == tmp_str)
    {
        free(tmp_str);
        tmp_str = NULL;
    }

    return 0;
}
