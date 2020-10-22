#include <stdio.h>
#pragma warning(disable : 4996)

void fibo(int num)
{
	int n1 = 1, n2 = 1, n3 = 1;
	int i;


	for (i = 1; i <= num; i++)
	{
		if (i >= 3)
		{
			n3 = n1 + n2;
			n1 = n2;
			n2 = n3;
		}

		printf("%d ", n3);
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);
	fibo(n);

	return 0;
}