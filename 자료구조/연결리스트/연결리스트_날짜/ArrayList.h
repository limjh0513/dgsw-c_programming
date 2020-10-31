#pragma once
#include <stdio.h>
#pragma warning(disable : 4996)

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
typedef int LData; // LData는 int 이다.
typedef struct __ArrayList {
	LData arr[LIST_LEN]; //int arr[100];
	int numOfData; // 리스트 갯수
	int curPosition; // 현재위치
}ArrayList; // 배열 리스트라는 자료구조를 만듦

typedef ArrayList List;

void ListInit(List* plist); // 리스트를 초기화
void LInsert(List* plist, LData data); // 리스트에 데이터 저장
int LFirst(List* plist, LData* pdata); // 첫번째 데이터가 pdata가 가르키는 곳에 저장
int LNext(List* plist, LData* pdata); // 참조된 데이터의 다음 데이터가 pdata가 가르키는 메모리에 저장
LData LRemove(List* plist); // LFirst또는 LNext 함수의 마지막 반환 데이터를 삭제
int LCount(List* plist); // 리스트 데이터 개수 반환