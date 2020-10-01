#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t, n, mid;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<vector<int>> sum(n, vector<int>(n)), dp(n, vector<int>(n, 2000000000));
		for (int j = 0; j < n; j++) {
			cin >> sum[j][j];
			dp[j][j] = 0;
		}
		if (n == 1) {
			cout << sum[0][0] << '\n';
			continue;
		}
		for (int j = 1; j < n; j++) {
			for (int k = 0; k < n - j; k++) {
				sum[k][k + j] = sum[k][k + j - 1] + sum[k + j][k + j];
				for (int mid = k; mid < k + j; mid++) {
					dp[k][k + j] = min(dp[k][k + j], sum[k][k + j] + dp[k][mid] + dp[mid + 1][k + j]);
				}
			}
		}
		cout << dp[0][n - 1] << '\n';
	}
}