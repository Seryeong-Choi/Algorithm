#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> maze(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> maze[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = maze[i][j] + max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
		}
	}
	
	cout << dp[n][m];
}