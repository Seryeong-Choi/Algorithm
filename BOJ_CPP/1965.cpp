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
	vector<int> boxes(n);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++)
		cin >> boxes[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i;j++) {
			if (boxes[j] < boxes[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}