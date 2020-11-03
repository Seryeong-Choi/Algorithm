#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s, m;
	cin >> n >> s >> m;
	vector<int> vol(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> vol[i];

	vector<vector<bool>> dp(n, vector<bool>(m + 1, false));
	if (s + vol[0] <= m)
		dp[0][s + vol[0]] = true;
	if (s - vol[0] >= 0)
		dp[0][s - vol[0]] = true;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j] && j + vol[i] <= m)
				dp[i][j + vol[i]] = true;
			if (dp[i - 1][j] && j - vol[i] >= 0)
				dp[i][j - vol[i]] = true;
		}
	}
	//
	bool flag = false;
	for(int j = m; j >= 0; j--)
		if (dp[n - 1][j]) {
			cout << j;
			flag = true;
			break;
		}
	if (!flag)
		cout << -1;
}