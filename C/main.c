/* C code below */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


bool exists(int ints[], int count, int k)
{
	int *res = (int*)bsearch(&k, ints, count, sizeof(int), cmpfunc);
	return (res != NULL);
}

int main(void)
{
	int ints[] = { -9, 14, 37, 102 };
	printf("%d\n", exists(ints, 4, 102)); // 1
	printf("%d\n", exists(ints, 4, 36)); // 0
	return 0;
}
