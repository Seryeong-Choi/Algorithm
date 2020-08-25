#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, num[1000], dp[1000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (num[j] < num[i])
				dp[i] = max(dp[i], dp[j] + 1);
	}

	int ans = *max_element(dp, dp + n);
	cout << ans << '\n';

	int num_chk = 1001;
	vector<int> seq;
	for (int i = n - 1; i >= 0; i--) {
		if (ans == 0)
			break;
		if (dp[i] == ans && num[i] < num_chk) {
			seq.push_back(num[i]);
			num_chk = num[i];
			ans--;
		}
	}

	for (int i = seq.size() - 1; i >= 0; i--)
		cout << seq[i] << ' ';
}