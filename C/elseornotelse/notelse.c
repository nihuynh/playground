int foo(int a, int low, int high)
{
	if (a > high)
		return (high);
	else if (a < low)
		return (low);
	return (a);
}