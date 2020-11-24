#include <stdio.h>
#pragma warning(disable : 4996)

#define SIZE 10

void push(int);
void pop();
void display();

int stack[SIZE];
int top = -1;

int main(void)
{
	int val, choice;
	while (1)
	{
		printf("\n----------MENU---------\n");
		printf("1. Push 2.Pop 3.Display 4.Exit\n");
		printf("Your Choice : ");
		scanf("%d", &choice);
		//���� : switch case ���� ����Ͽ�

		switch (choice)
		{
		case 1:
		{
			printf("���� �Է��ϼ��� : ");
			scanf("%d", &val);
			push(val);
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			display();
			break;
		}
		case 4:
		{
			printf("���α׷� ����...\n");
			return 0;
			break;
		}
		default:
			printf("�߸��� ���� �Է��߽��ϴ�.\n");
			break;
		}
	}

	return 0;
}

void push(int val)
{
	if (top == SIZE - 1)
	{
		printf("������ ����á���ϴ�.\n");
	}
	else
	{
		top++;
		stack[top] = val; // stack[++top] = val
	}
}

void pop()
{
	if (top == -1)
	{
		printf("������ ����ֽ��ϴ�.\n");
	}
	else
	{
		printf("%d", stack[top]); // stack[top--];
		top--;
	}
}

void display()
{
	if (top == -1)
	{
		printf("������ ����ֽ��ϴ�.");
	}
	else 
	{
		for (int i = top; i >= 0; i--)
		{
			printf("%4d", stack[i]);
		}
	}
	printf("\n");
}