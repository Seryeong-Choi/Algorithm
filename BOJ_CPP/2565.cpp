#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<pair<int, int>> lines;
	vector<int> dp(n, 1);

	int temp0, temp1;
	for (int i = 0; i < n; i++) {
		cin >> temp0;
		cin >> temp1;
		lines.push_back(pair<int, int>(temp0, temp1));
	}

	sort(lines.begin(), lines.end());

	int temp = 0;
	for (int i = 1; i < lines.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (lines[j].second < lines[i].second)
				temp = max(dp[j], temp);
		}
		dp[i] += temp;
		temp = 0;
	}

	cout << n - *max_element(dp.begin(), dp.end());
}