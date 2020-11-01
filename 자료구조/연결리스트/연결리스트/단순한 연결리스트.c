#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node* list_pointer;
typedef struct list_node {
	int data;
	list_pointer link;
	//struct list_node* link -> 이제 포인터
};

int main(void)
{
	list_pointer first, second;
	first = (list_pointer)malloc(sizeof(list_node));
	second = (list_pointer)malloc(sizeof(list_node));
	second->link = NULL;
	second->data = 20;
	first->data = 10;
	first->link = second;
	return 0;
}