#include <iostream>
#include <vector>

using namespace std;
vector<int> dp;

int solution(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;
	if (dp[n] != -1)
		return dp[n];

	dp[n] = (solution(n - 1) + 2 * solution(n - 2)) % 10007;
	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	dp.assign(n+1, -1);

	cout << solution(n);
}