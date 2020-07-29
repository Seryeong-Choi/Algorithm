#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> dp(41, make_pair(-1, -1));

pair<int, int> solution(int n) {
	if (n == 0)
		return pair<int, int>(1, 0);
	if (n == 1)
		return pair<int, int>(0, 1);

	if (dp[n] != pair<int, int>(-1, -1))
		return dp[n];

	dp[n] = make_pair(solution(n - 1).first + solution(n - 2).first, solution(n-1).second + solution(n-2).second);

	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> input;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		input.push_back(temp);
	}

	pair<int, int> ans;
	for (int i : input) {
		ans = solution(i);
		cout << ans.first << " " << ans.second << "\n";
	}
}