#include <stdio.h>
#pragma warning(disable : 4996)
int pbo(int n)
{
	/*if (n == 1) 시작을 0부터
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}*/
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	
	else
	{
		return pbo(n-1) + pbo(n - 2);
	}
}

int main(void)
{
	int i;

	for (i = 1; i <= 5; i++)
	{
		printf("%d ", pbo(i));
	}

	return 0;
}