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
#pragma warning(disable : 4996)

#define R 100 //보석의 갯수 Row
#define C 10000 //가방의 크기 Column

int b[R + 1][C + 1];//가방 bag
int w[R + 1];//각 보석의 무게 weight
int p[R + 1];//보석의 가격 price
int main(void)
{
	int myBagsize = 0;
	int nJewels = 0;
	int i, j;
	scanf("%d", &myBagsize); //도둑 가방
	scanf("%d", &nJewels); //보석 갯수

	for (i = 1; i <= nJewels; i++)
	{
		scanf("%d %d", &w[i], &p[i]);
	}
	for (i = 1; i <= nJewels; i++)
	{
		for (j = 1; j <= myBagsize; j++)
		{
			if (j >= w[i] && b[i-1][j] <= (b[i-1][j-w[i]]+p[i]))
			{
				b[i][j] = b[i - 1][j - w[i]] + p[i];
			}
			else
			{
				b[i][j] = b[i - 1][j];
			}
		}
	}

	printf("%d\n", b[nJewels][myBagsize]);
	return 0;
}