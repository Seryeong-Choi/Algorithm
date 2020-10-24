#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board, dp;
int solution(int x, int y) {
	if (x <= 0 || y <= 0)
		return 0;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = board[x][y] + solution(x - 1, y) + solution(x, y - 1) - solution(x - 1, y - 1);
	return dp[x][y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, x1, y1, x2, y2;
	cin >> n >> m;
	board.assign(n + 1, vector<int>(n + 1, 0));
	dp.assign(n + 1, vector<int>(n + 1, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i + 1][j + 1];
		
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << solution(x2, y2) - solution(x2, y1 - 1) - solution(x1 - 1, y2) + solution(x1 - 1, y1 - 1);
		cout << '\n';
	}
}