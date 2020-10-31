#pragma once
#include <stdio.h>
#pragma warning(disable : 4996)

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
typedef int LData; // LData�� int �̴�.
typedef struct __ArrayList {
	LData arr[LIST_LEN]; //int arr[100];
	int numOfData; // ����Ʈ ����
	int curPosition; // ������ġ
}ArrayList; // �迭 ����Ʈ��� �ڷᱸ���� ����

typedef ArrayList List;

void ListInit(List* plist); // ����Ʈ�� �ʱ�ȭ
void LInsert(List* plist, LData data); // ����Ʈ�� ������ ����
int LFirst(List* plist, LData* pdata); // ù��° �����Ͱ� pdata�� ����Ű�� ���� ����
int LNext(List* plist, LData* pdata); // ������ �������� ���� �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����
LData LRemove(List* plist); // LFirst�Ǵ� LNext �Լ��� ������ ��ȯ �����͸� ����
int LCount(List* plist); // ����Ʈ ������ ���� ��ȯ