### switch
- switch 语句一定要记得写 break
- switch 的条件只能是 int 类型

### 
++a 性能比 a++ 好

### 数组
- 数组在内存中是连续存储的
- 定义数组的时候最好使用常量，使用的时候就无所谓，但是注意不能越界
- 数组名是常量，不能赋值
- 数组名是数组首元素地址
- 可以通过数组的总内存大小除以单个元素内存大小求数组长度

### 二维数组
- 内存中没有多维数组的概念，多维数组是一维数组的特殊例子
- 如果在定义时同时初始化，那么第一个中括号可以不写内容，例: int arr[][3]
- 可以通过 sizeof 来求二维数组的行和列

### 字符数组
- c语言没有字符串类型，是用字符数组模拟的
- 字符串一定是字符数组，字符数组不一定是字符串
- 如果字符数组以字符 '\0' 结尾，那么就是字符串('\0'等价于0)
- 字符数组可以直接使用 %s 输出，如果没有结束符会导致打印乱码
- 初始化的时候如果没有初始化完，那么剩下的会自动补0
- 初始化数组一般用字符串初始化，它会自动在末尾加上结束符 char a[] = "abc";
- \0 后面别跟数字，可能会组成转义字符
- char a[] = "\0abc"; 会打印空字符串
- 在使用 scanf 输入字符串的时候不能有空格

### 随机数产生
1. 设置随机种子 srand(seed)  stdlib.h
2. 产生随机数 rand()  stdlib.h
3. 因为srand 如果 seed 一样的话每次产生的随机数都是一样的，所以引入 time.h
4. srand((unsigned int)time(NULL))

### 函数
- strchr() 查询字符是否在指定字符数组中，返回字符所在位置地址，如果查询失败返回 NULL 
- strstr() 查询字符串是否在指定字符数组中
- strtok() 字符串切割，会破坏本来的字符串，一般将源字符串复制一份再操作，如果没有切割成功那么会返回 NULL
- atoi() 将字符串转换为数字
- atof() atol()
- sscanf() 和 sprintf() 很常用，使用来提取数字等

### 自定义函数
- 没有返回值，使用 void 修饰
- 函数的参数及内部的变量，只有在调用的时候才会分配空间，调用 完毕自动释放
- 如果 return 的返回值和函数的返回类型不一样，那么以函数的返回类型为准
- return 和 exit 的区别是 return 中止当前函数，exit 退出整个程序
- 函数的声明不是必须要放在函数外边，只要在调用函数之前声明就行了，声明的时候可以不加 extern
- 一个函数只能定义一次，可以声明多次
- 声明的形参和定义的形参可以不一样
- 可以只声明函数，不定义，不过没有意义
- 声明时，形参名称可以不写，但是形参类型一定要写
- 在头文件中加入 #pragma once 可以防止头文件重复包含，也可以使用 #ifndef 的方式


### 指针
- 存储地址，32位编译器用4字节存储,64位编译器用8字节存储
- 指针就是地址，地址就是指针
- 指针和指针变量不一样
- 只有定义后的变量的地址才是合法的地址，使用未知的地址会导致野指针
- 空指针，给指针变量赋值为 NULL，在定义指针的时候赋值一个 NULL 是一个好习惯
- 也可以使用 p[0] 的方式操作指针所指向的值
- void * p; 万能指针
- 指针步长由指针指向的数据类型决定,所以在使用 void * 的时候要先将指针转为对应类型
- int const * p; 和 int * const p; 不一样，前面表示 p 指向的那个变量不能被改变，后面表示 p 不能被改变
- 指针的加减
- 指针数组和数组指针不一样
- p[i] 等价于 *(p + i)
- 如果想通过函数改变实参，那么必须使用地址方式传递
- 形参中的数组不是数组，是指针
- 绝对不能将局部变量的地址作为返回值，不然其它地方操作会出现野指针
- 每个字符串常量都是一个地址，该字符串首元素的地址
- 字符串常量放在 data 区，文字常量区，是只读的，尝试修改会出现野指针
- 字符指针和字符数组不一样，因为字符指针所指向的内存不能改变(常量特性)，而字符数组的值可以改变
  char *p = "hello";
  char buf[] = "hello";
- int main(int argc, char *arg[]); // argc 是后面数组的个数，*argc[] 是数组，其中的元素为 char *
- 值传递和地址传递，只要是传的变量就是值传递，不管该变量是不是指针
- 函数参数传指针的时候，int a[100]; int a[]; int *a; 都是一样的
- 全局变量，在程序结束过后才会释放

## 内存管理

### 变量作用域
- 普通全局变量(外部链接)
    1. 如果使用变量时，找不到该定义，需要声明，声明时不要赋值，extern int a;
    2. 在编译阶段分配空间，在整个程序运行完释放
    3. 如果定义一个全局变量，不赋值，则无法确定其是定义还是声明
    4. 定义全局变量，建议初始化，声明全局变量，建议加 extern
    5. 所有文件都能使用
- 普通局部变量
    1. 只有执行到这个变量的时候才会分配空间，{}执行完成后自动释放
    2. 在定义的时候可以加个修饰符 auto
    3. 如果不初始化，默认是随机数
- static 全局变量(内部链接)
    1. static 全局变量只能作用于当前文件
- static 局部变量
    1. 在编译阶段就分配空间，{}执行完不会自动释放
    2. 如果不初始化，默认为 0
    3. 初始化只能一次，赋值可以多次
    4. 在 data 区，只能使用常量初始化
- .h 文件只用来声明，不能在里面定义，不然出现重复定义 

### 内存分区
- 可使用 size a.out 查看内存分区
    1. text: 存放代码函数相关的区域，只读
    2. data: 存放初始化的数据，包含全局变量以及 static 变量以及文字常量区(只读)
    3. bss: 存放未初始化数据，包含未初始化的全局变量、static 变量
- 程序执行前内存分区已经确定，但是只有程序在运行时才会加载内存
- 运行程序的时候会根据已分配的内存先加载其内容，然后运行的时候会生成一个栈区 stack
- stack: 运行时产生，存放普通局部变量，内存自动管理，先进后出
- heap: 手动申请内存，手动释放内存
- 函数递归容易导致栈溢出

### 内存操作函数
- memset: 将指定内存的前 n 个字节设置为特定的值，常用来初始化或者清空某个字符数组的值
- memcpy: 将指定内存长度的内容复制到另一个内存，会将结束符之后的内容也复制
- memmove: 将指定内存移动到另一个内存(防止内存重叠)
- memcmp: 比较指定两个内存的内容是否相等，一个一个地址比
- malloc:
    1. 分配堆区内存，如果程序没有结束，不会释放，使用完过后一定要手动释放
    2. 同一块堆区内存只能释放一次
    3. free(p) 释放 p 所指向的内存。一般 free(p);和 p = NULL;联合起来使用
