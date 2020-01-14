/* C code below */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <stdbool.h>

typedef struct {
    long coin2;
    long bill5;
    long bill10;
} Change;

bool optimal_change(long s, Change *c)
{
    c->bill10 = s / 10;
    s -= c->bill10 * 10;
    c->bill5 = s / 5;
    s -= c->bill5 * 5;
    c->coin2 = s / 2;
    s -= c->coin2 * 2;
    return (s == 0);
}

int main(void)
{
	Change c;
	long s = 43; // Change this value to perform other tests
	optimal_change(s, &c);

	printf("Coin(s)  2€: %d\n", c.coin2);
	printf("Bill(s)  5€: %d\n", c.bill5);
	printf("Bill(s) 10€: %d\n", c.bill10);

	long result = c.coin2*2 + c.bill5*5 + c.bill10*10;
	printf("\nChange given = %d\n", result);
}