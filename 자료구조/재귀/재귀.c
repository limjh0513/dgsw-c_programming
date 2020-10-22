#include <stdio.h>
#pragma warning(disable : 4996)

void Recursive(int num)
{
	if (num <= 0)
	{
		return;
	}
	printf("Àç±Í È£Ãâ : %d!\n", num);
	Recursive(num - 1);
}

int main(void)
{
	Recursive(3);
	return 0;
}