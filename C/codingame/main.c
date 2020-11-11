#include <stdio.h>

int main()
{
	struct
	{
		int len;
	} *pointer = NULL;

	pointer->len = 10;
	++pointer->len; // increments len

	printf("%d\n", pointer->len);

	struct user
	{
		char *username;
		int id;
	} users[] = {
		{"admin", 0},
		{"leonardo", 1}};

	printf("%s", users[0].username);

	return 0;
}