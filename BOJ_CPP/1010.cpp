#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(101, -1);

int solution(int r, int n) {
	if (r == 1)
		return n;

	dp[r] = solution(r - 1, n) * (n + 1 - r) / r;
	return dp[r];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<pair<int, int>> ans;
	int temp1, temp2;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		ans.push_back(make_pair(temp1, temp2));
	}

	for (int i = 0; i < n; i++)
		cout << solution(ans[i].first, ans[i].second) << "\n";
}