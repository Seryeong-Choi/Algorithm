#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

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

	vector<int> dp = { 0,1,2,4 };

	for (int i = 4; i <= *max_element(input.begin(), input.end()); i++) 
		dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);

	for (int i : input)
		cout << dp[i] << "\n";
}
