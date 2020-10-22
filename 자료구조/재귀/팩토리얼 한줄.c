#include <stdio.h>
#pragma warning(disable : 4996)

int fac(int x)
{
	return (x == 1 ? x : x * fac(x - 1));
}

int main(void)
{
	printf("%d\n", fac(5));

	return 0;
}