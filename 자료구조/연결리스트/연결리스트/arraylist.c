#include <stdio.h>
#pragma warning(disable : 4996)

int main(void)
{
	int arr[100];
	int put = 1;
	int step = 0;

	printf("�ڿ��� �Է�, 0 �Է� �� ����\n");
	while (put != 0)
	{
		printf("�Է� : ");
		scanf("%d", &put);
		if (put < 1)
		{
			break;
		}
		arr[step] = put;
		step += 1;
	}

	printf("\n�Է� ���� ������ ���!\n");
	for (int i = 0; i < step; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	for (int i = 0; i < step; i++)
	{
		printf("%d��(��) �����մϴ�.\n", arr[i]);
	}

	return 0;
}