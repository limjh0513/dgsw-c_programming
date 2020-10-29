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
	Node* newNode = (Node*)malloc(sizeof(Node)); //���ο� ��� ����
	
	newNode->data = data; //���ο� ��忡 ������ �߰�

	newNode->next = plist->head->next; //�� ��尡 �ٸ� ��带 ����Ű�� ��
	plist->head->next = newNode; //���� ��尡 �� ��带 ����Ű�� ��

	//19, 20 ���� �ٲ�� �Ǹ� ���̳���� ���� �κ��� �� ��尡 �ǰ� �� ����� �����κ��� ���̳�尡 �ǹǷ� �ڵ尡 �̻�����
	
	(plist->numOfData)++; //����� ������ �� �ϳ� ����
}

void SInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //�� ��� ����
	Node* pred = plist->head; //pred�� ���̳�带 ����Ű�� ��
	newNode->data = data; // �� ����� data ���� data��

	//�� ��尡 �� ��ġ�� ã�� ���� �ݺ���
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	//pred�� ������ ��带 ����Ű�� �͵� �ƴϰ� �� �����Ͱ� �� �ڸ��� ã�� ���ߴٸ�
	//comp�� 0�� ��ȯ�ϴ� ���� ù��° ������ data�� ���� ������ �ռ���(���� �۾�) head�� �� ������� �ϴ� ��� -> while�� �ߴ�
	//comp�� 1�� ��ȯ�ϴ� ���� �ι�° ������ pred->next->data�� ���� ������ �ռ���(���� �۾�) head�� �� ������� �ϴ� ���
	{
		pred = pred->next; //���� ���� �̵�
	}

	newNode->next = pred->next; //�� ����� �������� ���� (pred->next�� ����Ű�� �ִ� ���� newNode->next�� ����Ű�� ��)
	pred->next = newNode;// ������� ������ ���� (pred->next�� newNode��)

	(plist->numOfData)++; //����� ������ �� �ϳ� ����
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL) // ���ı��� ���� X
	{
		FInsert(plist, data); //�Ӹ��� ��� �߰�(ù��° �߰�)
	}
	else
	{
		SInsert(plist, data);
	}
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)//���̳�尡 NULL�� ����Ű�� ��ȯ X
	{
		return FALSE;
	}

	plist->before = plist->head; //before�� ���̳�带 ����Ű�� ��
	plist->cur = plist->head->next; // cur�� ù ��° ��带 ����Ű�� ��

	*pdata = plist->cur->data; //ù��° ����� ������ ����
	return TRUE; //��ȯ O
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL) //cur�� NULL�� ����Ű�� (������ �κ�)
	{
		return FALSE; // ��ȯ X
	}

	plist->before = plist->cur; // cur�� ����Ű�� ���� before��
	plist->cur = plist->cur->next; //cur�� cur->next�� ����Ŵ

	*pdata = plist->cur->data; //cur�� data�� ����
	return TRUE; //��ȯ O
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur; //rpos�� cur�� ����Ű�� ��
	LData rdata = rpos->data; //rdata�� rpos�� data ���� ����
	plist->before->next = plist->cur->next; //before->next�� cur->next�� ���� (�Ҹ��� ����Ʈ���� ����)
	plist->cur = plist->before; //cur�� before�� �־� cur�� �Ѵܰ� ���� before�� ����(�������� ��ĭ) (��ġ ������)

	free(rpos); // ������� �ߴ� cur�� ����Ű�� rpos�� free(�����Ҵ� ����)����
	(plist->numOfData)--; //������ ������ �ϳ� �ٿ���
	return rdata;// rpos->data�� �����س��� rdata�� ��ȯ
}

int LCount(List* plist)
{
	return plist->numOfData; //numOfData�� ���� ��ȯ
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}