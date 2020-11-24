#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
	int x;
	int y;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;
	vector<string> map(r);
	vector<pos> water;
	vector<pos> mov = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	vector<vector<int>> visited(r, vector<int>(c, -1));
	pos start, beaver;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'D')
				beaver = { i, j };
			else if (map[i][j] == 'S') {
				start = { i, j };
				map[i][j] = '.';
			}
			else if (map[i][j] == '*')
				water.push_back({ i, j });
		}
	}

	queue<pos> q;
	q.push({ start.x, start.y});
	visited[start.x][start.y] = 0;
	pos front, next;
	int ans = -1;
	int time = 0;
	while (!q.empty()) {
		front = q.front();
		q.pop();
	
		if (time < visited[front.x][front.y]) {
			vector<pos> new_water;
			new_water = water;
			for (pos p : water) {
				for (int i = 0; i < 4; i++) {
					next = { p.x + mov[i].x , p.y + mov[i].y };
					if (next.x >= 0 && next.x < r && next.y >= 0 && next.y < c && map[next.x][next.y] == '.') {
						map[next.x][next.y] = '*';
						new_water.push_back({ next.x, next.y });
					}
				}
			}
			water = new_water;
			++time;
		}
		if (map[front.x][front.y] == '*')
			continue;

		bool flag = false;
		for (int i = 0; i < 4; i++) {
			next = { front.x + mov[i].x , front.y + mov[i].y };
			if (next.x >= 0 && next.x < r && next.y >= 0 && next.y < c) {
				if (map[next.x][next.y] == '.' && visited[next.x][next.y] == -1) {
					visited[next.x][next.y] = visited[front.x][front.y] + 1;
					q.push(next);
				}
				else if (map[next.x][next.y] == 'D') {
					ans = visited[front.x][front.y] + 1;
					flag = true;
					break;
				}
			}
		}
		if (flag)
			break;
	}
	if (ans == -1)
		cout << "KAKTUS";
	else cout << ans;
}