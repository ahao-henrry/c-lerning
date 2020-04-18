#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cfg.h"

#define FILENAME "cfg.ini"

int main(int argc, char** argv)
{

    char* key = (char*)malloc(100);
    char* value;
    printf("input key : ");
    scanf("%s", key);
    int ret = readCfg(FILENAME, key, &value);
    if(0 != ret)
    {
        return ret;
    }

    printf("value = %s\n", value);

    if(NULL != key)
    {
        free(key);
        key = NULL;
    }
    if(NULL != value)
    {
        free(value);
        value = NULL;
    }

    return 0;
}

void TWrite(char* key, char* value)
{
    while(1)
    {
        printf("input key(exit for return) : ");
        scanf("%s", key);
        if(NULL != strstr(key, "exit"))
        {
            break;
        }
        printf("input value : ");
        scanf("%s", value);

        writeCfg(FILENAME, key, value);
    }    


}
