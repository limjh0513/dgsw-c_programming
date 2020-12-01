#include <stdio.h>
#pragma warning(disable : 4996)

#define MAXQSIZE 5
int queue[MAXQSIZE];

void Enqueue(int* back, int item)
{
	if (*back == MAXQSIZE - 1)
	{
		printf("큐가 가득참\n");
		return;
	}
	queue[++ * back] = item;
}

int Dequeue(int* front, int back)
{
	if (*front == back)
	{
		printf("큐가 비었음\n");
		return 1;
	}
	return queue[++ * front];
}

void Display(int front, int back) {
	if (front == back)
	{
		printf("큐가 비었음\n");
	}
	for (int i = front; i < back; )
	{
		printf("%4d", queue[++i]);
	}
}

int main(void)
{
	int front = -1, back = -1;
	int menu, item;

	while (1)
	{
		printf("\n1. Enqueue 2. Dequeue 3.Display 4.Exit\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
		{
			scanf("%d", &item);
			Enqueue(&back, item);
			break;
		}
		case 2:
		{
			printf("%d ", Dequeue(&front, back));
			break;
		}
		case 3:
		{
			Display(front, back);
			break;
		}
		case 4:
			return 0;
		}
	}

	return 0;
}