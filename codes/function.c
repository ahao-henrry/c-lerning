#include <stdio.h>
#include <string.h>

int main() {
    char buf[] = "hello.ahhhhao.you.this.farewell";
    char* p = strtok(buf, ".");
    printf("%s\n", p);
    p = strtok(NULL, ".");
    printf("%s\n", p);

    return 0;
}

int main1() {
    char buf[10];
    fgets(buf, sizeof(buf), stdin);
    printf("%s\n", buf);

    return 0;
}

