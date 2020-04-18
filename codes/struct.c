#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person
{
    char name[30];
    int age;
} Person;

Person* createPerson(int num)
{
    Person* temp = NULL;
    temp = (Person*)malloc(sizeof(Person) * num);
    if(NULL == temp)
    {
        return NULL;
    }
    printf("temp : %p\n", temp);
    
    // 这里不需要返回在主调函数那里也能获取到此地址，但是不能要前面那句print
    return temp;
}

int main(int argc, char** argv)
{
    Person* person = NULL;
    int num = 3;
    person = createPerson(num);
    printf("%p\n", person);

    return 0;
}
