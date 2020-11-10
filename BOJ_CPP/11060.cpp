#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m, a, b;
	cin >> n;
	vector<int> maze(n, 0);
	for (int i = 0; i < n; i++)
		cin >> maze[i];
	vector<int> dp(n, 987654321);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] != 987654321) {
			for (int j = 0; j <= maze[i]; j++)
				if (i + j < n)
					dp[i + j] = min(dp[i] + 1, dp[i + j]);
		}
	}
	if (dp[n - 1] != 987654321)
		cout << dp[n - 1];
	else
		cout << -1;
}