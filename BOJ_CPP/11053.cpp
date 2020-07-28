#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> num(n, 0);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++)
		cin >> num[i];

	int temp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (num[j] < num[i])
				temp = max(dp[j], temp);
		dp[i] += temp;
		temp = 0;
	}

	cout << *max_element(dp.begin(), dp.end());
}