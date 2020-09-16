#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(3));
	dp[0] = { 1,1,1 };
	for(int i = 1; i < n; i++){
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}
	cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 9901;
}