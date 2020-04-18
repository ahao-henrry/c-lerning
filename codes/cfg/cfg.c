#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024
int writeCfg(char* fileName, char* key, char* value)
{
    FILE* fp = NULL;
    fp = fopen(fileName, "a");
    if(NULL == fp)
    {
        printf("open file fail.\n");
        return -1;
    }

    char* buf;
    buf = (char*)malloc(strlen(key) + strlen(value));
    if(NULL == buf)
    {
        return -2;
    }
    sprintf(buf, "%s=%s\n", key, value);
    int ret = fputs(buf, fp);
    if(ret <= 0)
    {
        return -3;
    }

    fclose(fp);

    return 0;
}


int readCfg(char* fileName, char* key, char** value)
{
    FILE* fp = NULL;
    fp = fopen(fileName, "r");
    if(NULL == fp)
    {
        return -1;
    }   
    char* tmp = (char*)malloc(100);
    char tmp_key[100]; 
    char* tmp_value = (char*)malloc(BUF_SIZE); 
    while(!feof(fp))
    {
        tmp = fgets(tmp, BUF_SIZE, fp);
        if(NULL == tmp)
        {
            return -1;
        }
        sscanf(tmp, "%[^=]=%s", tmp_key, tmp_value);
        if(0 == strcmp(tmp_key, key))
        {
            *value = tmp_value;
            goto FREE_TMP;
            return 0;
        }
    }
    *value = NULL;

FREE_TMP:
    if(NULL != tmp)
    {
        free(tmp);
        tmp = NULL;
    }
        
    return -1;
}
