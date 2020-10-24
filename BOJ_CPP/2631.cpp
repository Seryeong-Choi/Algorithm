#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> children(n, 0);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++)
		cin >> children[i];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (children[j] < children[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	cout << n - *max_element(dp.begin(), dp.end());
}