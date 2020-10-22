#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	static int n = 0;

	printf("%d\n", n++);
	if (n > 2000)
	{
		return 0;
	}
	main();

	return 0;
}