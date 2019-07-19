# include <stdlib.h>

int test1(void)
{
	void *leak;

	leak = malloc(100 * 1024);
	free(&leak);
	free(&leak);
	return (0);
}

int main(void)
{
	test1();
	return (0);
}
