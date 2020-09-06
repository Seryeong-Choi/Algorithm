#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct pos {
	int x, y;
};
int n, m, ans = 100000;
vector<vector<int>> board;
pos mov[4] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<pos> virus;
queue<pair<pos, int>> q;

int solution(vector<pos> v) {
	int result = 0;
	vector<vector<int>> cur_board = board;
	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i], 0 });
		cur_board[v[i].x][v[i].y] = 3;
	}
	//bfs

	pair<pos,int> front;
	int tx, ty;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			tx = front.first.x + mov[i].x;
			ty = front.first.y + mov[i].y;
			if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
				if (cur_board[tx][ty] == 0) {
					cur_board[tx][ty] = 9;
					q.push({ {tx, ty}, front.second + 1 });
					result = front.second + 1;
				}
				else if (cur_board[tx][ty] == 2) {
					cur_board[tx][ty] = 3;
					q.push({ { tx, ty }, front.second + 1 });
				}	
			}
		}
	}
	
	for(vector<int> v: cur_board)
		for(int i: v)
			if (i == 0) {
				result = 100000;
				break;
			}

	return result;
}

void dfs(vector<pos> v, int index) {
	if (v.size() == m) 
		ans = min(ans, solution(v));

	else {
		for (int i = index; i < virus.size(); i++) {
			v.push_back(virus[i]);
			dfs(v, i + 1);
			v.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	board.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push_back({ i,j });
		}
	vector<pos> v;
	dfs(v, 0);
	if (ans == 100000)
		ans = -1;
	cout << ans;
}