#include <stdio.h>
#pragma warning(disable : 4996)

void name(int n)
{
	if (n > 0)
	{
		printf("ÀÓÀçÇö\n");
		name(n - 1);
	}
	else
	{
		return;
	}
}

int main(void) {
	int n;

	scanf("%d", &n);
	name(n);

	return 0;
}
