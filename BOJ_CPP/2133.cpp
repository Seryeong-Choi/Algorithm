#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;
int solution(int n) {
	if (n % 2 == 1)
		return 0;

	if (n == 2)
		return 3;

	if (dp[n] != -1)
		return dp[n];

	dp[n] = 2 + solution(n - 2) * 3;

	for (int i = 2; i < n - 4; i += 2)
		dp[n] += 2 * solution(i);

	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	dp.assign(n + 1, -1);

	cout << solution(n);
}