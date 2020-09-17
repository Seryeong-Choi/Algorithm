#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;
vector<vector<long long>> dp;

long long solution(int x, int y) {
	if (x == n - 1 && y == n - 1)
		return 1;
	if (x > n-1 || y > n-1 || board[x][y] == 0)
		return 0;
	if (dp[x][y] != -1)
		return dp[x][y];
	int nx, ny;
	nx = x + board[x][y];
	ny = y + board[x][y];
	dp[x][y] = solution(nx, y) + solution(x, ny);
	return dp[x][y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n;
	board.assign(n, vector<int>(n));
	dp.assign(n, vector<long long>(n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	//output
	cout << solution(0, 0);

}