#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp(101, -1);

long long solution(int n) {
	if (n == 1 || n == 2 || n == 3)
		return 1;
	if (n == 4 || n == 5)
		return 2;

	if (dp[n] != -1)
		return dp[n];

	dp[n] = solution(n - 1) + solution(n - 5);
	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> ans;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ans.push_back(temp);
	}

	for (int i : ans)
		cout << solution(i) << "\n";
}