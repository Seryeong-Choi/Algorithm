#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<int> t(n, 0), p(n,0);
	vector<pair<int, int>> dp(n, { -1,-1 });
	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];
	int ans = 0;
	//dp
	for (int i = n-1; i>=0; i--) {
		if (i + t[i] <= n) 
			dp[i] = { p[i], i };
		for (int j = i + 1; j < n; j++) {
			//i에서 상담할때
			if (i + t[i] <= dp[j].second)
				dp[i] = max(dp[i], { p[i] + dp[j].first, i });
			//i에서 상담하지 않을 때
			dp[i] = max(dp[i], dp[j]);
		}
		ans = max(dp[i].first, ans);
	}
	cout << ans;
}