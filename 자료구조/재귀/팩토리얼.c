#include <stdio.h>
#pragma warning(disable : 4996)
int fac(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else
	{
		return num * fac(num - 1);
	}
}
int main(void)
{
	int n;
	int result = 0;

	scanf("%d", &n);

	result = fac(n);

	printf("%d", result);
	return 0;
}