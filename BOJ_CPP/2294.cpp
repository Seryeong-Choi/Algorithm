#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> coins, dp;
int solution(int sum, int index) {
	if (sum <= 0)
		return 0;
	if (dp[sum] != 99999)
		return dp[sum];

	for (int i = index; i < n; i++)
		if(sum - coins[i] >= 0)
			dp[sum] = min(dp[sum], 1 + solution(sum - coins[i], i));

	return dp[sum];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	coins.assign(n, 0);
	dp.assign(k + 1, 99999);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		dp[coins[i]] = 1;
	}
	sort(coins.begin(), coins.end());
	int ans = solution(k, 0);

	if (ans == 99999) cout << -1;
	else cout << ans;
}