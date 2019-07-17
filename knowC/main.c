
# include <stdio.h>
struct S
{
	int i;
	char c;
} s;

int test1()
{
	return sizeof(*(&s));
}
int test2()
{
  char a = 0;
  short int b = 0;
  return sizeof(b) == sizeof(a+b);
}
int test3()
{
  int i = 0;
  return i++ + ++i;
}


int main(void)
{
	printf("test1 : %d\n", test1());
	printf("test2 : %d\n", test2());
	printf("test3 : %d\n", test3());
	return 0;
}
