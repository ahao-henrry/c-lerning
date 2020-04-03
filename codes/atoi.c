#include <stdio.h>
#include <string.h>

int my_atoi(char *in); 
int my_sum(char *in); 

int main(int argc, char *arg[]){
    if(NULL == arg[1]) {
        printf("please input number.\n");
        return 1;
    }

    char *in = arg[1];
    int sum = my_sum(in);
    printf("%d\n", sum);

    char *str = "23,43,1,445,2";

    return 0;
}

int my_atoi(char *in) {
    int i = 0;
    int sum = 0;
    while('\0' != in[i]) {
        sum = sum * 10 + (in[i] - '0');
        i++;
    }

    return sum;
}

int my_sum(char *in) {
    char *temp = in;
    int number = 0;
    int sum = 0;
    char *num;
    num = strtok(temp, ",");
    while(NULL != num) {
        number = my_atoi(num);
        sum += number;
        num = strtok(NULL, ",");
    }

    return sum;
}
