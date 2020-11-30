#include <stdio.h>
#pragma warning(disable : 4996)

#define SIZE 8
int map[SIZE + 1][SIZE + 1] = {//인접행렬
{0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0}, //1
{0,1,0,1,1,0,0,0,0}, //2
{0,0,1,0,0,0,0,1,0}, //3
{0,0,1,0,0,1,0,0,0}, //4
{0,0,0,0,1,0,1,0,0}, //5
{0,0,0,0,0,1,0,1,1}, //6
{0,0,0,1,0,0,1,0,1}, //7
{0,0,0,0,0,0,1,1,0} // 8
};

int v[SIZE + 1];//visited
int queue[100];
int front = 0, back = 0;
int main(void)
{
	v[1] = 1; //1번 노드 부터 순회
	queue[back++] = 1; //1번 노드 부터 탐색하는 것을 큐에 잠시 저장
	int row; //행      column->열(세로)
	do {
		row = queue[front++]; //row <-- 1줄 가져옴
		for (int i = 1; i <= SIZE + 1; i++)
		{
			if (map[row][i] == 1 && v[i] == 0)
			{
				printf("%d->%d ", row, i);
				queue[back++] = i;
				v[i] = 1;
			}
		}
	} while (front != back);
	printf("\n");


	return 0;
}