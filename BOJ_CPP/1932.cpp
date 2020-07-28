#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<vector<int>> dp(500, vector<int>(500, -1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> dp[i][j];

	for (int i = 1 ; i < n ; i++) {
		for (int j = 0 ; j < i + 1 ; j++) {
			if (j == 0)
				dp[i][j] = dp[i][j] + dp[i - 1][0];
			else if (j == i)
				dp[i][j] = dp[i][j] + dp[i - 1][i - 1];
			else
				dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	cout << *max_element(dp[n-1].begin(),dp[n-1].end());
}