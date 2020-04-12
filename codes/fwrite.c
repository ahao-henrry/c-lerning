#include <stdio.h>

typedef struct Person {
    int age;
    char name[50];
    int gender;
} Person;

int main() {
    FILE *fp = NULL;
    fp = fopen("./fwrite", "r");
    if(NULL == fp) {
        perror("file error");
	return -1;
    }

    Person person;
    fread(&person, sizeof(Person), 1, fp);

    printf("age = %d\n", person.age);
    printf("name = %s\n", person.name);
    printf("gender = %d\n", person.gender);

    fclose(fp);

    return 0;
}

void write() {
    FILE *fp = NULL;
    fp = fopen("./fwrite", "w");
    if(NULL == fp) {
        perror("file error");
	return;
    }

    Person person = {18, "ahao", 1};
    fwrite(&person, 1, sizeof(person), fp);

    fclose(fp);

}
