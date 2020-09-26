#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<vector<int>> board, dp;
vector<pair<int, int>> mov = { {1,0}, {0,1},{-1,0},{0,-1} };

int solution(int x, int y) {
	if (x < 0 || y < 0 || x == m || y == n)
		return 0;
	if (x == m - 1 && y == n - 1)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	pair<int, int> nxt;
	for (int i = 0; i < 4; i++) {
		nxt.first = x + mov[i].first;
		nxt.second = y + mov[i].second;
		if (nxt.first >= 0 && nxt.first < m && nxt.second >= 0 && nxt.second < n && board[nxt.first][nxt.second] < board[x][y])
			dp[x][y] += solution(nxt.first, nxt.second);
	}
	return dp[x][y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	board.assign(m, vector<int>(n));
	dp.assign(m, vector<int>(n, -1));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	solution(0, 0);

	cout << dp[0][0];
}