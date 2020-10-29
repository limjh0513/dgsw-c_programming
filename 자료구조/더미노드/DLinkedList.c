#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //새로운 노드 생성
	
	newNode->data = data; //새로운 노드에 데이터 추가

	newNode->next = plist->head->next; //새 노드가 다른 노드를 가르키게 함
	plist->head->next = newNode; //더미 노드가 새 노드를 가르키게 함

	//19, 20 줄이 바뀌게 되면 더미노드의 다음 부분이 새 노드가 되고 새 노드의 다음부분이 더미노드가 되므로 코드가 이상해짐
	
	(plist->numOfData)++; //저장된 데이터 수 하나 증가
}

void SInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //새 노드 생성
	Node* pred = plist->head; //pred는 더미노드를 가르키게 함
	newNode->data = data; // 새 노드의 data 값은 data로

	//새 노드가 들어갈 위치를 찾기 위한 반복문
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	//pred가 마지막 노드를 가르키는 것도 아니고 새 데이터가 들어갈 자리를 찾지 못했다면
	//comp가 0을 반환하는 것은 첫번째 인자인 data가 정렬 순서상 앞서서(값이 작아) head에 더 가까워야 하는 경우 -> while문 중단
	//comp가 1을 반환하는 것은 두번째 인자인 pred->next->data가 정렬 순서상 앞서서(값이 작아) head에 더 가까워야 하는 경우
	{
		pred = pred->next; //다음 노드로 이동
	}

	newNode->next = pred->next; //새 노드의 오른쪽을 연결 (pred->next가 가르키고 있던 곳을 newNode->next가 가르키게 함)
	pred->next = newNode;// 새노드의 왼쪽을 연결 (pred->next를 newNode로)

	(plist->numOfData)++; //저장된 데이터 수 하나 증가
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL) // 정렬기준 마련 X
	{
		FInsert(plist, data); //머리에 노드 추가(첫번째 추가)
	}
	else
	{
		SInsert(plist, data);
	}
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)//더미노드가 NULL을 가르키면 반환 X
	{
		return FALSE;
	}

	plist->before = plist->head; //before는 더미노드를 가르키게 함
	plist->cur = plist->head->next; // cur는 첫 번째 노드를 가르키게 함

	*pdata = plist->cur->data; //첫번째 노드의 데이터 전달
	return TRUE; //반환 O
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL) //cur가 NULL을 가르키면 (마지막 부분)
	{
		return FALSE; // 반환 X
	}

	plist->before = plist->cur; // cur가 가르키던 것을 before로
	plist->cur = plist->cur->next; //cur를 cur->next로 가르킴

	*pdata = plist->cur->data; //cur의 data를 전달
	return TRUE; //반환 O
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur; //rpos에 cur를 가르키게 함
	LData rdata = rpos->data; //rdata에 rpos의 data 값을 넣음
	plist->before->next = plist->cur->next; //before->next에 cur->next를 넣음 (소멸대상 리스트에서 제거)
	plist->cur = plist->before; //cur를 before로 넣어 cur를 한단계 전인 before로 만듬(왼쪽으로 한칸) (위치 재조정)

	free(rpos); // 지우고자 했던 cur를 가르키는 rpos를 free(동적할당 해제)해줌
	(plist->numOfData)--; //데이터 갯수를 하나 줄여줌
	return rdata;// rpos->data를 저장해놨던 rdata를 반환
}

int LCount(List* plist)
{
	return plist->numOfData; //numOfData의 수를 반환
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}