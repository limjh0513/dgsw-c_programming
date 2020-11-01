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
	printf("자연수를 입력하세요.(단 0 입력 시 종료)\n\n");

	while (1)
	{
		printf("입력 : ");
		scanf("%d", &num);
		if (num < 1)
		{
			break;
		}
		newNode = (Node*)malloc(sizeof(Node)); //new
		newNode->data = num;
		newNode->next = NULL;
		if (head == NULL) //아직 head node를 사용하지 않은 경우(맨 처음)
		{
			head = newNode;
		}
		else
		{
			tail->next = newNode;
		}
		tail = newNode;
	}
	printf("\n--연결리스트 데이터 출력==\n");
	if (head == NULL)
	{
		printf("데이터 없음");
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
		printf("%d 삭제\n", head->data);
		Node* nextNode = head->next;
		free(node);
		while (nextNode != NULL)
		{
			node = nextNode;
			printf("%d 삭제\n", node->data);
			nextNode = nextNode->next;
			free(node);
		}
		printf("모든 메모리 해제\n");
	}
	return 0;
}