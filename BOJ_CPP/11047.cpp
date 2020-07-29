#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> coins, int k) {
	int ans = 0;
	for (int i = coins.size() - 1; i >= 0 ; i--) {
		ans += k / coins[i];
		k %= coins[i];
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;

	vector<int> coins(n, 0);
	for (int i = 0 ; i < n ; i++)
		cin >> coins[i];

	cout << solution(coins, k);
}