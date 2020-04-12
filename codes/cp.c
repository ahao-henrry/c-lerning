#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* srcFp = NULL;
    srcFp = fopen(argv[1], "r");
    if(NULL == srcFp)
    {
        perror("src file");
        return -1;
    }

    FILE* destFp = NULL;
    destFp = fopen(argv[2], "w");
    if(NULL == destFp)
    {
        perror("dest file");
        return -1;
    }
    
    int temp[1024];
    int ret = 0;
    while((ret = fread(temp, 1, sizeof(temp), srcFp)) != 0)
    {
        fwrite(temp, 1, ret, destFp); 
    }

    fclose(srcFp);
    srcFp = NULL;
    fclose(destFp);
    destFp = NULL;

    return 0;
}

