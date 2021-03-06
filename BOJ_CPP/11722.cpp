#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> dp(n, -1);
	vector<int> num(n, 0);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (num[i] < num[j])
				dp[i] = max(dp[j] + 1, dp[i]);
	}

	cout << *max_element(dp.begin(), dp.end());
}