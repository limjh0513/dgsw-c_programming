#include <iostream>
#define MAX 5
#pragma warning(disable : 4996)
using namespace std;
int stack[MAX];
int top = -1; //top, push, pop
bool PUSH(int val) 
{
	//TRUE, FALSE
	if (top >= MAX - 1)
	{
		cout << "������ ��ħ" << endl;
		return false;
	}
	stack[++top] = val;
	cout << "���ÿ� �Է°� : " << val << endl;
	cout << "\n";
	return true;
}


bool POP() {
	if (top <= -1)
	{
		cout << "������ ���������" << endl;
		return false;
	}
	cout << "�� : " << stack[top--] << endl;
	return true;
}

int main(void)
{

	int menu, n;
	
	while (1) {
		cout << "1.PUSH, 2.POP, 3.EXIT\n" << endl;
		cin >> menu;
		if (menu == 1)
		{
			cout << "���ÿ� ���� �� : ";
			cin >> n;
			PUSH(n);
		}
		else if (menu == 2)
		{
			POP();
		}
		else if (menu == 3)
			break;
	}
	return 0;
}