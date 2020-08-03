#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> maze;
vector<vector<int>> visited; //방문여부
vector<int> pos[4] = { {0,-1},{0,1},{-1,0},{1,0} }; // 상하좌우
vector<vector<int>> dist;//루트에서의 거리
vector<vector<pair<int,int>>> parent;//부모 노드
int n, m;
queue<pair<int,int>> q;

bool isValid(int x, int y) { //인덱스 체크
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	else return false;
}

void bfs(int x, int y) {
	q.push(make_pair(x, y)); 
	visited[x][y] = 1;
	dist[x][y] = 1;
	parent[x][y] = make_pair(0, 0);

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int i = x + pos[k][0];
			int j = y + pos[k][1];
			if (isValid(i, j) && maze[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				dist[i][j] = dist[x][y] + 1;
				parent[i][j] = make_pair(x, y);
				q.push(make_pair(i, j));
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	maze.assign(n, vector<int>(m,0));

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			maze[i][j] = s[j] - '0';
	}

	visited.assign(n, vector<int>(m, 0));
	dist.assign(n, vector<int>(m, 0));
	parent.assign(n, vector<pair<int,int>>(m, make_pair(0,0)));
	bfs(0, 0);

	cout << dist[n - 1][m - 1];
}