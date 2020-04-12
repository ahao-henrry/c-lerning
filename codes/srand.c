#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int i = 0;
	srand((unsigned int)time(NULL)); 
	while(i < 100) {
		int num = rand();
		printf("%d,", num);
		i++;
	}

	return 0;
}
