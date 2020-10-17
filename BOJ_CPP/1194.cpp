#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct pos {
	int x;
	int y;
};

struct moon {
	int cnt;
	int key;
	pos p;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	pos start;
	vector<pos> mov = { {0,1}, {0,-1}, {1,0}, {-1,0} };
	int n, m, ans = 987654321;
	cin >> n >> m;
	vector<string> maze(n);
	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(64, false)));
	for (int i = 0; i < n; i++) {
		cin >> str;
		maze[i] = str;
		for(int j = 0; j < m; j++)
			if (maze[i][j] == '0') {
				start = { i,j };
				maze[i][j] = '.';
				break;
			}
	}

	queue<moon> q;
	moon now;
	q.push({ 0, 0, start });
	visited[start.x][start.y][0] = true;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.cnt < ans) {
			pos nxt;
			for (int i = 0; i < 4; i++) {
				nxt = { now.p.x + mov[i].x, now.p.y + mov[i].y};
				//cout << nxt.x << ' ' << nxt.y << endl;
				if (nxt.x >= 0 && nxt.x < n && nxt.y >= 0 && nxt.y < m && !visited[nxt.x][nxt.y][now.key]) {
					if (maze[nxt.x][nxt.y] == '1')
						ans = min(ans, now.cnt + 1);
					else if (maze[nxt.x][nxt.y] == '.') {
						visited[nxt.x][nxt.y][now.key] = true;
						q.push({ now.cnt + 1, now.key, nxt });
					}
					else if (maze[nxt.x][nxt.y] == '#')
						continue;
					else if (maze[nxt.x][nxt.y] >= 'a' && maze[nxt.x][nxt.y] <= 'f') { //키얻음
						int new_key = 1 << (maze[nxt.x][nxt.y] - 'a');
						visited[nxt.x][nxt.y][now.key | new_key] = true;
						q.push({ now.cnt + 1, now.key | new_key, nxt });
					}
					else if (maze[nxt.x][nxt.y] >= 'A' && maze[nxt.x][nxt.y] <= 'F') { //키사용
						int door = 1 << (maze[nxt.x][nxt.y] - 'A');
						int chk = door & now.key;
						if (chk == door) {
							visited[nxt.x][nxt.y][now.key] = true;
							q.push({ now.cnt + 1, now.key, nxt });
						}
					}
				}
			}
		}
	}

	if (ans == 987654321) cout << -1;
	else cout << ans;
}