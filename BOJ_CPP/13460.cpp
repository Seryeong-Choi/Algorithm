#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct beads {
	int Rx;
	int Ry;
	int Bx;
	int By;
	int count;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, ans = 11;
	vector<string> board;
	vector<pair<int, int>> mov = { {1,0},{0,1},{-1,0},{0,-1} };
	cin >> n >> m;
	beads b;
	b.count = 0;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		board.push_back(str);
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				b.Rx = i;
				b.Ry = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				b.Bx = i;
				b.By = j;
				board[i][j] = '.';
			}
		}
	}
	queue<beads> q;
	q.push(b);
	beads now, nxt;

	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nxt = { now.Rx + mov[i].first, now.Ry + mov[i].second, now.Bx + mov[i].first, now.By + mov[i].second, now.count + 1 };
			if (nxt.count < ans) {
				if (board[nxt.Rx][nxt.Ry] == '#' && board[nxt.Bx][nxt.By] == '#')
					continue;
				else if ((now.Rx == now.Bx && ((i == 1 && now.Ry > now.By) || (i == 3 && now.Ry < now.By)))
					|| (now.Ry == now.By && ((i == 0 && now.Rx > now.Bx) || (i == 2 && now.Rx < now.Bx)))) { //R부터 이동
					while (board[nxt.Rx][nxt.Ry] == '.' && !(nxt.Rx == now.Bx && nxt.Ry == now.By)) {
						nxt.Rx += mov[i].first;
						nxt.Ry += mov[i].second;
					}
					if (board[nxt.Rx][nxt.Ry] != 'O') { //빨간색 빠졌으면 아래에서 재체크
						nxt.Rx -= mov[i].first;
						nxt.Ry -= mov[i].second;
					}
					while (board[nxt.Bx][nxt.By] == '.' && !(nxt.Rx == nxt.Bx && nxt.Ry == nxt.By)) {
						nxt.Bx += mov[i].first;
						nxt.By += mov[i].second;
					}
					if (board[nxt.Bx][nxt.By] == 'O') // 파란색 빠짐
						continue;
					else if(board[nxt.Rx][nxt.Ry] == 'O') { //빨간색 빠졌는지 체크
						ans = min(ans, nxt.count);
						break;
					}
					//둘다안빠졌으면
					nxt.Bx -= mov[i].first;
					nxt.By -= mov[i].second;
					q.push(nxt);
				}
				else {//B부터이동
					while (board[nxt.Bx][nxt.By] == '.' && !(nxt.Bx == now.Rx && nxt.By == now.Ry)) {
						nxt.Bx += mov[i].first;
						nxt.By += mov[i].second;
					}
					if (board[nxt.Bx][nxt.By] == 'O') {// 파란색 빠짐
						continue;
					}
					nxt.Bx -= mov[i].first;
					nxt.By -= mov[i].second;
					while (board[nxt.Rx][nxt.Ry] == '.' && !(nxt.Rx == nxt.Bx && nxt.Ry == nxt.By)) {
						nxt.Rx += mov[i].first;
						nxt.Ry += mov[i].second;
					}
					if (board[nxt.Rx][nxt.Ry] == 'O') {
						ans = min(ans, nxt.count);
						break;
					}
					nxt.Rx -= mov[i].first;
					nxt.Ry -= mov[i].second;
					q.push(nxt);
				}
			}
		}
	}

	if (ans == 11) cout << -1;
	else cout << ans;
}