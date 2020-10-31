#include "ArrayList.h"

int main(void)
{
	printf("실행 날짜 : %s\n", __DATE__);
	printf("실행 시간 : %s\n", __TIME__);
	printf("라인 번호 : %d\n", __LINE__);
	printf("파일 경로 : %s\n", __FILE__);
	List list;
	int data;
	ListInit(&list);
	// 5개 데이터를 저장해보자!
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);

	//저장된 데이터 갯수 출력
	printf("현재 데이터 갯수 : %d\n", LCount(&list));
	
	//숫자 2를 삭제
	//int LFirst(List* plist, LData* pdata);
	if (LFirst(&list, &data))
	{
		if (data == 2)
		{
			LRemove(&list);
		}

		while (LNext(&list, &data))
		{
			if (data == 2)
			{
				LRemove(&list);
			}
		}
	}
	printf("현재 데이터 갯수 : %d\n", LCount(&list));
	//남은 데이터 보기
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	} 
	printf("\n\n");
	return 0;
}