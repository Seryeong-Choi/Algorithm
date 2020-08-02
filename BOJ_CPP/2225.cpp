#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
int solution(int n, int k) {
	if (k == 1)
		return 1;

	if (n == 1)
		return k;
	
	if (dp[n][k] != -1)
		return dp[n][k];

	dp[n][k] = (solution(n - 1,k) + solution(n, k - 1)) % 1000000000;

	return dp[n][k];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	dp.assign(n + 1, vector<int>(k+1, -1));

	cout << solution(n, k);
}