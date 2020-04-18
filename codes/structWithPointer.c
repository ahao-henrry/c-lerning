#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person
{
    char name[30];
    char** rname;
    int age;
} Person;

int createPerson(Person** person, int num)
{
    Person* temp = NULL;
    temp = (Person*)malloc(sizeof(Person) * num);
    if(NULL == temp)
    {
        return -1;
    }
    printf("temp : %p\n", temp);
    memset(temp, 0, sizeof(Person) * num);

    int i;
    for(i = 0; i < num; i++)
    {
        printf("input name : ");
        scanf("%s", temp[i].name);
        printf("input age : ");
        scanf("%d", &(temp[i].age));

        char** sname = (char**)malloc(24);
        if(NULL == sname)
        {
            return -1;
        }
        int j;
        for(j = 0; j < 3; j++)
        {
            char* sname_tmp = (char*)malloc(30);
            if(NULL == sname_tmp)
            {
                return -1;
            }
            printf("input sname:");
            scanf("%s", sname_tmp);
            *(sname + j) = sname_tmp;
        }

        temp[i].rname = sname;
    }

    *person = temp;
    
    return 0;
}

int main(int argc, char** argv)
{
    Person* person = NULL;
    int num = 2;
    int ret = createPerson(&person, num);
    printf("%p\n", person);
    
    if(0 != ret)
    {
        return ret;
    }

    int i,j;
    for(i = 0; i < num; i++)
    {
        printf("person%d name = %s\n", i, person[i].name);
        printf("person%d age = %d\n", i, person[i].age);
        for(j = 0; j < 3; j++)
        {
            printf("person%d rname%d = %s\n", i, j, person[i].rname[j]);
        }
    }

    return 0;
}
