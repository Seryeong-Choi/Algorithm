#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> dp(1000001, -1);

int solution(int x) {
	if (x == 1)
		return 0;
	
	if (dp[x] != -1)
		return dp[x];

	dp[x] = 1 + solution(x - 1);
	if (x % 3 == 0)
		dp[x] = min(1 + solution(x / 3), dp[x]);
	if (x % 2 == 0)
		dp[x] = min(1 + solution(x / 2), dp[x]);

	return dp[x];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int x;
	cin >> x;
	cout << solution(x);
}
