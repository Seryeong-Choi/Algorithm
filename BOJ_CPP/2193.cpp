#include <vector>
#include <iostream>

using namespace std;

vector<long long> dp(91, -1);
long long solution(int n) {
	if (n == 1 || n == 2)
		return 1;

	if (dp[n] != -1)
		return dp[n];

	dp[n] = solution(n - 1) + solution(n - 2);
	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	cout << solution(n);
}