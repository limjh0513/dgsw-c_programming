/* 문제
알리바바라는 도둑이 보석가게에서 보석을 훔치려고 한다.
알리바바는 n무게를 넣을 수 있는 크기의 가방을 메고 있다.
여러개 보석을 가방에 넣을 때 n무게보다 커지면 가방이 찢어져 쓸 수가 없다.
그리고 보석은 단단해서 적당한 크기로 쪼갤 수 없고 종류당 1개씩만 있다.
예를 들어 30kg을 가져갈 수 있는 가방과
보석 종류가 3가지가 있다고 가정하자.
A보석 5kg, 50억, B보석 10kg, 60억
C보석 20kg, 140억일 때 알리바바가 가져갈 수 있는 최대이익은
B와 C보석을 가져가 200억이 된다.
우리는 알리바바가 가장 큰 이익이 날때의 값을 출력하는 프로그램을 작성할 것이다.

첫 줄에는 도둑이 가져갈 수 있는 무게를,
다음 줄에는 보석의 개수,
다음 줄 부터는 각 보석의 무게와 값이 한 줄에 하나씩 입력된다.
가방의 크기는 10000 이하이고, 보석의 개수는 100 개 이하
무게와 가격은 200 이하의 정수이다.


입력
30
3
5 50
10 60
20 140

출력
30
3
5 50
15 60
20 140

출력
190
*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main(void)
{
	int bag = 0;//가방 무게
	int jew = 0;//보석 갯수;
	int* jew_KG; //무게
	int* jew_pri; //가격
	int i;
	int bag_kg; //현재 가방 무게
	int money = 0; //돈
	int big_money = 0;//최대이득

	scanf("%d", &bag);
	scanf("%d", &jew);
	jew_KG = (int*)malloc(sizeof(int) * jew);
	jew_pri = (int*)malloc(sizeof(int) * jew);
	for (i = 0; i < jew; i++)
	{
		scanf("%d %d", &jew_KG[i], &jew_pri[i]);
	}

	for (i = 0; i < jew; i++)
	{
		for (int j = i; j < jew; j++)
		{
			money = 0;
			bag_kg = 0;

			if (jew_KG[j] <= bag)
			{
				bag_kg += jew_KG[j];
				money += jew_pri[j];
			}
			else
			{
				continue;
			}
			if (big_money < money)
			{
				big_money = money;
			}

			for (int k = i + 1; k < jew; k++)
			{
				if (bag_kg + jew_KG[k] <= bag)
				{
					bag_kg += jew_KG[k];
					money += jew_pri[k];
				}
				else
				{
					continue;
				}
				if (big_money < money)
				{
					big_money = money;
				}
				printf("%d %d\n", money, bag_kg);
				bag_kg -= jew_KG[k];
				money -= jew_pri[k];
			}
		}
	}

	printf("%d", big_money);
	free(jew_KG);
	free(jew_pri);
	return 0;
}