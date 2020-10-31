#include "ArrayList.h"

int main(void)
{
	printf("���� ��¥ : %s\n", __DATE__);
	printf("���� �ð� : %s\n", __TIME__);
	printf("���� ��ȣ : %d\n", __LINE__);
	printf("���� ��� : %s\n", __FILE__);
	List list;
	int data;
	ListInit(&list);
	// 5�� �����͸� �����غ���!
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);

	//����� ������ ���� ���
	printf("���� ������ ���� : %d\n", LCount(&list));
	
	//���� 2�� ����
	//int LFirst(List* plist, LData* pdata);
	if (LFirst(&list, &data))
	{
		if (data == 2)
		{
			LRemove(&list);
		}

		while (LNext(&list, &data))
		{
			if (data == 2)
			{
				LRemove(&list);
			}
		}
	}
	printf("���� ������ ���� : %d\n", LCount(&list));
	//���� ������ ����
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	} 
	printf("\n\n");
	return 0;
}