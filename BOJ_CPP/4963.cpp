#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> map(50, vector<int>(50, -1));
vector<vector<int>> visited(50, vector<int>(50, 0));
vector<pair<int, int>> pos = { {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };
queue<pair<int, int>> q;
int h, w, ans;

bool isValid(int x, int y) {
	if (x >= 0 && y >= 0 && x < h && y < w) return true;
	else return false;
}

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		int n, m;
		for (int i = 0 ; i < 8 ; i++) {
			n = x + pos[i].first;
			m = y + pos[i].second;
			if (isValid(n, m) && visited[n][m] == 0 && map[n][m] == 1) {
				q.push(make_pair(n, m));
				visited[n][m] = 1;
			}
		}
		q.pop();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) // 종료조건
			break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		ans = 0;
		fill(visited.begin(), visited.end(), vector<int>(50,0)); // 초기화
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (visited[i][j] == 0 && map[i][j] == 1) {
					bfs(i, j);
					ans++;
				}
		
		cout << ans << "\n";
	}
}