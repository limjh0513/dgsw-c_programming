#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	int arr[100];
	int put = 1;
	int step = 0;

	printf("자연수 입력, 0 입력 시 종료\n");
	while (put != 0)
	{
		printf("입력 : ");
		scanf("%d", &put);
		if (put < 1)
		{
			break;
		}
		arr[step] = put;
		step += 1;
	}

	printf("\n입력 받은 데이터 출력!\n");
	for (int i = 0; i < step; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	for (int i = 0; i < step; i++)
	{
		printf("%d을(를) 삭제합니다.\n", arr[i]);
	}

	return 0;
}