#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);

	if( *(int*)a < *(int*)b )
		return -1;
	else if( *(int*)a == *(int*)b )
		return 0;
	else return 1;
}

int find_smallest_interval(int n, int numbers[n])
{
	qsort(numbers, n, sizeof(int), compare);

	int interval = numbers[n] - numbers[0];
	for(int i = 0 ; i < n; i++ ) {
      fprintf(stderr, "%d ", numbers[i]);
   }
   fprintf(stderr, "interval : %d\n", interval);
    return -1;
}

int main()
{
    int ints[] = { -9, 14, 37, 102 };
   printf("Before sorting the list is: \n");
   for(int n = 0 ; n < 5; n++ ) {
      printf("%d ", ints[n]);
   }
   qsort(ints, 5, sizeof(int), compare);
   printf("\nAfter sorting the list is: \n");
   for(int n = 0 ; n < 5; n++ ) {
      printf("%d ", ints[n]);
   }
   return(0);
}


    for(int i = 0 ; i < 5; i++ ) {
      printf("%d ", numbers[i]);
   }
   qsort(numbers, n, sizeof(int), compare);
   printf("\nAfter sorting the list is: \n");
   for(int i = 0 ; i < 5; i++ ) {
      printf("%d ", numbers[i]);
   }