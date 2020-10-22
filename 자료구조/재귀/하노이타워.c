#include <stdio.h>
#pragma warning(disable : 4996)
void hanoi(int n, char from, char by, char to)
{
	if (n == 1)
	{
		printf("1은 %c에서 %c로 이동\n", from, to);
	}
	else
	{
		hanoi(n - 1, from, to, by);
		printf("%d는 %c에서 %c로 이동\n", n, from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main(void)
{
	hanoi(5, 'A', 'B', 'C');

	return 0;
}


//원판이 n개일 때 2^n - 1번의 이동으로 원판을 모두 옮길 수 있다.