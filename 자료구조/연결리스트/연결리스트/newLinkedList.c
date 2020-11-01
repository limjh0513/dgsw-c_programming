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
	Node* cur = NULL;
	Node* newNode = NULL;
	int num;
	printf("�ڿ����� �Է��ϼ���.(�� 0 �Է� �� ����)\n\n");

	while (1)
	{
		printf("�Է� : ");
		scanf("%d", &num);
		if (num < 1)
		{
			break;
		}
		newNode = (Node*)malloc(sizeof(Node)); //new
		newNode->data = num;
		newNode->next = NULL;
		if (head == NULL) //���� head node�� ������� ���� ���(�� ó��)
		{
			head = newNode;
		}
		else
		{
			tail->next = newNode;
		}
		tail = newNode;
	}
	printf("\n--���Ḯ��Ʈ ������ ���==\n");
	if (head == NULL)
	{
		printf("������ ����");
	}
	else
	{
		cur = head;
		printf("%d  ", cur->data);
		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n");
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		Node* node = head;
		printf("%d ����\n", head->data);
		Node* nextNode = head->next;
		free(node);
		while (nextNode != NULL)
		{
			node = nextNode;
			printf("%d ����\n", node->data);
			nextNode = nextNode->next;
			free(node);
		}
		printf("��� �޸� ����\n");
	}
	return 0;
}