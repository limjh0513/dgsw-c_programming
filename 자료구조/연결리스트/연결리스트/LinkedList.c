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
	printf("자연수를 입력하세요.(단 입력 0 입력 시 종료)\n");
	
	while (1)
	{
		printf("입력 : ");
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