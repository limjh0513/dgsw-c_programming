#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct _node Node;
typedef struct _node {
	int data;
	Node* next;
};

int main(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL; // CURRENT
	Node* newNode = NULL;
	int num;
	printf("�ڿ����� �Է��ϼ���.(�� �Է� 0 �Է� �� ����)\n");
	
	while (1)
	{
		printf("�Է� : ");
		scanf("%d", &num);
		if (num < 1)
		{
			break;
		}
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = num;
		newNode->next = NULL;
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			tail->next = newNode;
		}
		tail = newNode;
	}

	return 0;
}