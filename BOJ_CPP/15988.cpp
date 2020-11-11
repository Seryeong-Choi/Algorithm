#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> t;

	vector<int> dp(1000001, -1);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i <= 1000000; i++)
		dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000009 + dp[i - 3]) % 1000000009;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}