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
	vector<int> cost(n, 0), app_memory(n, 0);
	vector<vector<int>> dp(n, vector<int>(10001, 0));
	for (int i = 0; i < n; i++)
		cin >> app_memory[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	bool flag = false;
	int ans = 0;
	for (int c = 0; c < 10001; c++) {
		if (cost[0] <= c)
			dp[0][c] = app_memory[0];
		for (int i = 1; i < n; i++) {
			if (cost[i] <= c)
				dp[i][c] = max(dp[i - 1][c], app_memory[i] + dp[i - 1][c - cost[i]]);
			else
				dp[i][c] = dp[i - 1][c];
			if (dp[i][c] >= m) {
				flag = true;
				ans = c;
				break;
			}	
		}
		if (flag)
			break;
	}
	cout << ans;
}