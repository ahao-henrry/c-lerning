#include <stdio.h>

int main() {
    char arr[4] = {'a', 'h', 'a', 'o'};
    printf("%s\n", arr);

    return 0;
}

int main6() {
    char arr[100];
    printf("type str : \n");
    scanf("%s", arr);
    printf("your input is : %s\n", arr);

    return 0;
}

int main5() {
    int arr[] = {2, -1, 3, 56, 222, -456, 123, 52343, 22};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    int temp;
    int i = 0;
    int j = arr_len - 1;
    while(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[i] = temp;
        i++;
        j--;
    }
    for(i = 0; i < arr_len; ++i) {
        printf("%d,", arr[i]);
    }
    printf("\n");

    return 0;
}

int main4() {
    int arr[] = {2, -1, 3, 56, 222, -456, 123, 52343, 22};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    int max = arr[0];
    int i;
    for(i = 1; i < arr_len; ++i) {
        if(max < arr[i]){
            max = arr[i];
        }
    }

    printf("max = %d\n", max);

    return 0;
}

int main3() {
    int a = 10;
    int b = 20;
    int c = 30;
    int max = a;

    if(max < b)
    {
        max = b;
    }
    if(max < c)
    {
        max = c;
    }
    printf("max = %d\n", max);

    return 0;
}

int main2() {
    int arr[10] = {};
    int i;
    for(i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

int main1() {
    int array[10];
    int i;
    for(i = 0; i < 10; i++) {
        array[i] = i;
    }
    for(i = 0; i < 10; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
