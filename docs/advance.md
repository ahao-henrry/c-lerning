## 基础数据类型

```c
int b[10];
printf("b=%d, b+1=%d, &b=%d, &b+1=%d\n", b, b+1, &b, &b+1);
```

以上 b 是数组首元素地址，&b 是整个数组得地址



## 一级指针

```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  int main()
  {
      char buf[20] = "aaaa";
      char buf2[] = "bbbb";
      char *p = "aaaa";
      char *p1 = (char *)malloc(100);
      strcpy(p1, "126836");
  
      printf("buf = %X, p = %X\n", buf, p);
  
      return 0;
  }
```

- 上面这段代码 buf 和 p 得输出是不一样得，因为 buf 是在栈上分配得内存，然后把 aaaa 得值拷贝到 buf，而 p 是指向一个常量区得 aaaa 得地址

- 一般在被调函数中使用辅助变量接收形参得值做操作，不轻易改变形参
- 一般使用指针作为形参作为输出参数



```c
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  
  int main(int argc, char** argv)
  {
      const int a = 2;
      printf("a = %d\n", a);
  
      char* p = NULL;
      p = &a;
      *p = 3;
      printf("a = %d\n", a)
  
      return 0;
  }
```

- 以上这段代码，a 是使用 const 修饰的，但是可以通过 a 的地址间接修改 a 的值



## 二级指针

- 当使用一级指针得地址作为实参传给被调用函数得时候，被调用函数得形参需要为二级指针

- 函数参数有输入和输出特性

- int buf[10];  buf 本质是一个常量指针，就是说不能给它赋值



### 内存模型1

指针数组

```c
char* buf[] = {"aa", "cc", "bb"};
```



### 内存模型2

二维数组

```c
char buf[10][20] = {"aa", "cc", "bb"};
```

这种内存模型和第一种的区别是指针所指向的内存的数据类型不一样，导致步长不一样



### 内存模型3

```c
int num = 3;
char** p = NULL;
p = (char*)malloc(sizeof(char*) * num);
char* subP0 = (char*)malloc(sizeof(char) * 20);
strcpy(subP0, "aa");
p[0] = subP0;
char* subP1 = (char*)malloc(sizeof(char) * 20);
strcpy(subP1, "cc");
p[1] = subP1;
char* subP2 = (char*)malloc(sizeof(char) * 20);
strcpy(subP2, "bb");
p[2] = subP2;

// do something

free(subP0);
free(subP1);
free(subP2);
free(p);
```

![image-20200411202204350](./media/二级指针内存模型3.png)

当使用 malloc 循环分配内存的时候，如果中断了，可以使用 goto 语句将已分配的内存释放

```c
for()
{
    char* p = (char*)malloc(size);
    if(NULL == p)
    {
        goto FREE_MEM;
    }
}

FREE_MEM:
for()
{
    if(NULL != p)
    {
        free(p);
    }
}
```





## 二维数组

### 自定义数组类型

```c
typedef int (MyArray)[10];
MyArray myArray;
int i;
for(i = 0; i < 10; i++)
{
    myArray[i] = i+1;
}
```

- 二维数组在作为参数的时候会退化成一个数组指针



### 数组指针

定义一个指针，该指针指向一个数组，该指针就叫数组指针

#### 第一种定义方法

```c
typedef int (MyArray)[10];
int arr[10];
MyArray* pArray;
pArray = &arr;
```



#### 第二种定义方法

```c
typedef int (*PArray)[10];
int arr[10];
PArray pArray;
pArray = &arr;
```



#### 第三种定义方法 

```c
int (*pArray)[10];
int arr[10];
pArray = &arr;
```



#### 数组指针和多维数组的关系

```c
#include <stdio.h>                                                                 
#include <string.h>                                                                
#include <stdlib.h>                                                                

int main(int argc, char** argv)                                                    
{                                                                                  
    int a[3][5];                                                                   
    int i, j, k = 0;                                                               
    for(i = 0; i < 3; i++)                                                         
    {                                                                              
        for(j = 0; j < 5; j++)                                                     
        {                                                                          
            a[i][j] = k++;                                                         
        }                                                                          
    }                                                                              

    for(i = 0; i < 3; i++)                                                         
    {                                                                              
        for(j = 0; j < 5; j++)                                                     
        {                                                                          
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);                             
        }                                                                          
    }                                                                              

    int (*pArray)[5];                                                              
    pArray = a;                                                                    
    for(i = 0; i < 3; i++)                                                         
    {                                                                              
        for(j = 0; j < 5; j++)                                                     
        {                                                                          
            printf("a[%d][%d] = %d\n", i, j, pArray[i][j]);                        
        }                                                                          
    }      
    
    printf("pArray = %p, &a[0] = %p\n", pArray, &a[0]);
    printf("pArray+1 = %p, &a[1] = %p\n", pArray+1, &a[1]);

    return 0;                                                                      
}                             
```

- 数组指针相当于二维数组的首元素地址
- 数组指针 +i 相当于第 i 个元素地址
- 同理可得，*(pArray+i) +j 为第 i 行第 j 列的地址
- 同理可得，\*(*(pArray+i) +j ) 为第 i 行第 j 列的值



## 结构体

结构体的三种定义及初始化方法

#### 第一种

```c
typedef struct Person
{
    char name[30];
    int age;
} Person;

Person person;
person = {"henry", 18};
```



#### 第二种

```c
struct Person
{
    char name[30];
    int age;
} person;
person = {"henry", 18};
```



#### 第三种

```c
struct
{
    char name[30];
    int age;
} person = {"henry", 18};
```



- person.age = 18; 点操作符是寻址操作，找到 age 相对于 person 的偏移量，并不操作内存， 等号操作符才操作内存
- 当使用结构体作为参数的时候是进行值传递的，所以要想在被调函数中修改主调函数中的结构体的话，需要将结构体使用指针的方式将地址传给被调函数



### 深拷贝和浅拷贝

#### 浅拷贝

拷贝地址

#### 深拷贝

拷贝值，要想深拷贝，要先分配内存，然后复制值过去



### 结构体偏移量问题

- 可以通过结构体中某一个数据类型的地址求整个大的结构体地址或者其它数据类型地址，所以 定义好了结构体过后不能修改其中数据类型的相对位置，不然会和动态库对应不上导致野指针



- 当主调函数想通过一个参数获取结果的时候，主调函数分配内存的参数叫输入参数，被调函数分配内存的参数叫输出参数
- 一般情况下上层应用不使用 malloc，直接使用数组分配内存