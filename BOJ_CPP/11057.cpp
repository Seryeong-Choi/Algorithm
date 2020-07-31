#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
int solution(int i, int j) {
	if (i == 1)
		return 1;
	if (j == 0)
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = (solution(i, j - 1) + solution(i - 1, j)) % 10007;
	return dp[i][j];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	dp.assign(n + 1, vector<int>(10, -1));
	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + solution(n, i)) % 10007;

	cout << ans;
}