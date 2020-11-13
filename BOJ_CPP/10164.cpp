#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	dp[0][1] = 1;
	if (k == 0) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m;j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		cout << dp[n][m];
	}
	else {
		int x = (k - 1) / m + 1;
		int y = (k - 1) % m + 1;
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		int first = dp[x][y];
		dp[x - 1][y] = 1;
		dp[x][y - 1] = 0;

		for (int i = x; i <= n; i++)
			for (int j = y; j <= m; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

		cout << first * dp[n][m];
	}
}