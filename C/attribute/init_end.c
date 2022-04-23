#include <stdio.h>

void __attribute__((constructor)) init(void) {
    printf("Starting the program !\n");
}

void __attribute__((destructor)) end(void) {
    printf("Closing the program !\n");
}

int main(void) {
    printf("Inside the main !\n");
	if (1 > 0) {
		exit(1);
	}
	return 0;
}