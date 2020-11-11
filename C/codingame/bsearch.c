#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}


bool exists(int ints[], int count, int k)
{
    int *res;

    res = NULL;
    res = bsearch(&k, ints, count, sizeof(int), compare);
    return (res != NULL);
}

int main()
{
    int ints[] = { -9, 14, 37, 102 };
    printf("%d\n", exists(ints, 4, 39)); // 1
    printf("%d\n", exists(ints, 4, 36)); // 0
}