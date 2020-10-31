#include "ArrayList.h"

//ListInit(&list);
void ListInit(List* plist)
{ //����Ʈ ó�� �ܰ�
	(plist->numOfData) = 0; //����Ʈ ������ 0
	(plist->curPosition) = -1; //����Ʈ ���� ��ġ�� -1
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData > LIST_LEN) //100���� ������
	{
		printf("������ �Ұ���, ���� ���� ����...!\n");
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