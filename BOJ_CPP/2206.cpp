#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int map[1001][1001] = { };
int dist[1001][1001] = { };
int wall[1001][1001] = { };
pair<int, int> parent[1001][1001]{ make_pair(-1, -1) };
vector<vector<int>> pos = { {0,-1},{1,0},{0,1},{-1,0} };
queue<vector<int>> q;
int n, m;

bool isValid(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	else return false;
}

void bfs() { //bfs
	dist[0][0] = 1;
	parent[0][0] = make_pair(0, 0);
	wall[0][0] = 0;
	q.push(vector<int>{0, 0});

	int x, y, a, b;
	while (!q.empty()) {
		x = q.front()[0];
		y = q.front()[1];
		for (int i = 0; i < 4; i++) {
			a = x + pos[i][0];
			b = y + pos[i][1];
			if (isValid(a, b) && map[a][b] == 0 && dist[a][b] < 1) {
				dist[a][b] = dist[x][y] + 1;
				parent[a][b] = make_pair(x, y);
				wall[a][b] = wall[x][y];
				q.push({a, b});
				if (a == n - 1 && b == m - 1)
					return;
			}
			else if (isValid(a, b) && map[a][b] == 1 && wall[x][y] == 0){
				dist[a][b] = dist[x][y] + 1;
				parent[a][b] = make_pair(x, y);
				wall[a][b] = 1;
				q.push({a,b});
				if (a == n - 1 && b == m - 1)
					return;
			}
			else if (map[a][b] == 0 && dist[a][b] != 0 && wall[a][b] == 1 && wall[x][y] == 0) {
				dist[a][b] = dist[x][y] + 1;
				parent[a][b] = make_pair(x, y);
				wall[a][b] = wall[x][y];
				q.push({a,b});
			}
		}
		q.pop();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j] = s[j] - '0';
	}
	//bfs
	dist[n - 1][m - 1] = -1;
	bfs();
	//output
	cout << dist[n - 1][m - 1];
}