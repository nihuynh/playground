// C++ implementation below
#include <iostream>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <algorithm>
#include <vector>

using namespace std;

class Answer
{
public:
	static int compare(const void *a, const void *b)
	{
		return (*(int *)a - *(int *)b);
	}

	static bool exists(int ints[], int count, int k)
	{
		return (bsearch(&k, ints, sizeof(int), count, compare) != NULL);
	}
};