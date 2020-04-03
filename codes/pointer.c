#include <stdio.h>

int main(int argc, char *arg[]) {
    int *arr[10];
    printf("arr.len = %d\n", sizeof(arr));
    printf("arr[0].len = %d\n", sizeof(arr[0]));

    return 0;
}

void fun(){
    printf("%p\n", "heu");
    printf("%p\n", "she");
}

int main4(){
    fun();
    printf("%p\n", "you");
    printf("%p\n", "you");
    printf("%p\n", "are");
    printf("%p\n", "bit");

    return 0;
}

void swap(int *a, int *b);

int main3() {
   int a = 10;
   int b = 20;
   swap(&a, &b);
   printf("a = %d, b = %d\n", a, b);

   return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main2() {
    char src[100] = "hello";
    char dest[100];

    int i;
    for(i = 0; i < sizeof(src); i++) {
        if('\0' != src[i]) {
            dest[i] = src[i];
        }
    }
    dest[i] = 0;
    printf("dest = %s\n", dest);

    return 0;
}

int main1() {
   // 假如 a 的地址为 0xaabb
   int a = 10;
   printf("&a = %p\n", &a);
   //那么 p = 0xaabb,*p = 10 ,假如 p 的地址为 0xaab1
   int *p = &a;
   printf("p = %p, *p = %d\n", p, *p);
   //那么 q = 0xaab1,*q = 0xaabb, **q = 10, 假如 q 的地址为 0xaab2
   int **q = &p;
   printf("q = %p, *q = %p, **q = %d\n", q, *q, **q);
   //那么 t = 0xaab2,*t = 0xaab1,**t = 0xaabb, ***t = 10
   int ***t = &q;
   int ****m = &t;

   return 0;
}
