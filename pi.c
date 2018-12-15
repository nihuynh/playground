# include <stdio.h>
# include <math.h>

int main(void)
{
	long double carry;

	carry = M_PI / 360;
	printf("result is %.*Lf\n", 32, carry);
	return (0);
}
