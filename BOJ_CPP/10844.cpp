#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> dp(101,vector<int>(10,-1));

int solution(int n, int a) { // 가치리턴
	if (n == 1)
		return 1;

	if (dp[n][a] != -1)
		return dp[n][a];
	
	if (a == 0)
		dp[n][a] = solution(n - 1, a + 1) % 1000000000;
	else if (a == 9)
		dp[n][a] = solution(n - 1, a - 1) % 1000000000;
	else
		dp[n][a] = (solution(n - 1, a - 1) + solution(n - 1, a + 1)) % 1000000000;
	return dp[n][a];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += solution(n, i);
		ans %= 1000000000;
	}
	
	cout << ans;
}