/*
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0 0
2
4 4
6 6


*/

#include <stdio.h>
#pragma warning(disable : 4996)

#define X 10 //x
#define Y 10 //y

int main(void)
{
	int board[Y][X];
	int i, j;
	int x, y, n;

	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	scanf("%d", &n); //뒤집어야 할 x,y 좌표 갯수 받기
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		for (j = 0; j < X; j++)
		{
			if (board[y][j] == 0) //y축은 고정 x축 변경
			{
				board[y][j] = 1;
			}
			else
			{
				board[y][j] = 0;
			}
		}
		for (j = 0; j < Y; j++)
		{
			if (board[j][x] == 0) //x축은 고정 y축 변경
			{
				board[j][x] = 1;
			}
			else
			{
				board[j][x] = 0;
			}
		}
	}

	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}


	return 0;
}