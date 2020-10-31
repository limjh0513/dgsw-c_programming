#include "ArrayList.h"

//ListInit(&list);
void ListInit(List* plist)
{ //리스트 처음 단계
	(plist->numOfData) = 0; //리스트 갯수는 0
	(plist->curPosition) = -1; //리스트 현재 위치는 -1
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData > LIST_LEN) //100개가 넘으면
	{
		printf("저장이 불가능, 저장 공간 부족...!\n");
		return;
	}
	plist->arr[plist->numOfData] = data; // plist -> arr[0] = data;
	(plist->numOfData)++; //1, 2, 3....
}

int LCount(List* plist)
{
	return plist->numOfData;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
	{
		return FALSE;
	}

	(plist->curPosition) = 0;

	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)
	{
		return FALSE;
	}

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];
	for (i = rpos; i < num - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}
	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}