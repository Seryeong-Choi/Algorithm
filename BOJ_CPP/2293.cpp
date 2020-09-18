#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	int n, k;
	vector<int> coins;
	vector<int> dp;
	cin >> n >> k;
	coins.assign(n, 0);
	dp.assign(k + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	
	int ans = 0;
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for(int j = 1; j <= k; j++)
			if(j >= coins[i])
				dp[j] += dp[j - coins[i]];
	//output
	cout << dp[k];
}