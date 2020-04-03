#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
//    int arr[5] = {-4, 2, 4, -1, 3};
    int arr[5];
    int i,j,temp;
    srand((unsigned int)time(NULL));
    for(i = 0; i < 5; i++) {
        arr[i] = rand();
    }

    for(i = 0; i < 5; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(i = 0; i < 5; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

}

