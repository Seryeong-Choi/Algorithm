#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> wine(10001, 0);
vector<int> dp(10001, -1);
int solution(int n) {
	if (n == 0)
		return wine[0];
	if (n == 1)
		return wine[1] + wine[0];
	if (n == 2)
		return max(wine[1] + wine[0], max(wine[2] + wine[0], wine[2] + wine[1]));

	if (dp[n] != -1)
		return dp[n];

	dp[n] = max(solution(n - 1), max(wine[n] + solution(n - 2), wine[n] + wine[n - 1] + solution(n - 3)));
	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	cout << solution(n);
}