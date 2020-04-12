#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countStr(char *str, char *sub, int *count);

int main(int argc, char** argv)
{
    char *str = "ahao is me, ahao is you, ahao is everyone";
    char *sub = "ahao";
    int count = 0;

    int ret = countStr(str, sub, &count);
    if(0 != ret)
    {
        printf("count error, code = %d\n", ret);
        return ret;
    }

    printf("count = %d\n", count);

    return 0;
}

int countStr(char *str, char *sub, int *count)
{
    char *tmpStr = str;
    char *tmpSub = sub;
    int num = 0;

    while((tmpStr = strstr(tmpStr, tmpSub)) != NULL)
    {
        num++;
        tmpStr += strlen(tmpSub);
    }

    *count = num;

    return 0;
}
