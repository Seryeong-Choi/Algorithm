#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct horse {
	int x;
	int y;
	int count;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, w, h;
	vector<vector<int>> board(200, vector<int>(200));
	vector<vector<vector<int>>> chk(200, vector<vector<int>>(200, vector<int>(31, 987654321)));
	vector<vector<int>> jump = { {-2, -1}, {-1, -2},{-2, 1},{-1, 2},{2, -1},{1, -2},{2, 1},{1, 2} };
	vector<vector<int>> mov = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> board[i][j];
	
	queue<horse> q;
	q.push({ 0, 0, 0 });
	chk[0][0][0] = 0;
	horse front, next;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			next = { front.x + mov[i][0], front.y + mov[i][1], front.count };
			if (next.x >= 0 && next.x < h && next.y >= 0 && next.y < w && board[next.x][next.y] == 0
				&& chk[front.x][front.y][front.count] + 1 < chk[next.x][next.y][next.count]) {
				q.push(next);
				chk[next.x][next.y][next.count] = chk[front.x][front.y][front.count] + 1;
			}
		}
		if (front.count < k) {
			for (int i = 0; i < 8; i++) {
				next = { front.x + jump[i][0], front.y + jump[i][1], front.count + 1 };
				if (next.x >= 0 && next.x < h && next.y >= 0 && next.y < w && board[next.x][next.y] == 0
					&& chk[front.x][front.y][front.count] + 1 < chk[next.x][next.y][next.count]) {
					q.push(next);
					chk[next.x][next.y][next.count] = chk[front.x][front.y][front.count] + 1;
				}
			}
		}
	}
	int ans = *min_element(chk[h - 1][w - 1].begin(), chk[h - 1][w - 1].end());
	if (ans == 987654321)
		cout << -1;
	else cout << ans;
}