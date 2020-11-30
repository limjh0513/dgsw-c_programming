#include <stdio.h>
#pragma warning(disable : 4996)

int n;
int map[31][31];
int visited[31];
void DFS(int v)
{
	visited[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (map[v][i] == 1 && !visited[i])
		{
			//v���� i�� ���±��� �ְ� �湮���� ���� ���
			//printf("%d���� %d�� �̵�\n", v, i);
			printf("%d ", i);
			DFS(i);
		}
	}
}

int main(void)
{
	int startV; //������
	int v1, v2; //���� v1, v2

	scanf("%d", &n);
	scanf("%d", &startV);
	while (1) {
		scanf("%d %d", &v1, &v2);
		if (v1 == -1 && v2 == -1)
		{
			break;
		}
		map[v1][v2] = map[v2][v1] = 1;
	}
	printf("%d ", startV);
	DFS(startV);
	return 0;
}

/*
8
1
1 2
1 3
2 4
2 5
4 8
5 8
3 6
3 7
6 8
7 8
-1 -1
*/