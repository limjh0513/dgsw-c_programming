#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n = 7;
int visited[7];
vector<int> map[8];

void bfs(int startV) {
	queue<int> q; //1차원 배열 느낌
	q.push(startV);
	visited[startV] = true; //visited[startV] = 1
	while (!q.empty())
	{
		int front = q.front();
		int col;
		q.pop();
		cout << front << " "; //printf("%d ", front);
		for (int i = 0; i < map[front].size(); i++)
		{
			col = map[front][i];
			if (!visited[col]) { //방문하지 않았다면
				q.push(col);
				visited[col] = true;
			}
		}
	}
}

int main(void) {
	//1-2, 1-3 연결
	map[1].push_back(2);
	map[2].push_back(1);
	map[1].push_back(3);
	map[3].push_back(1);
	map[2].push_back(3);
	map[3].push_back(2);

	bfs(1);
	return 0;
}