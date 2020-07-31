#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> num(n, 0);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num.begin(), num.end());

	int sum = 0, ans = 0;
	do {
		for (int i = 0 ; i < n - 1 ; i++)
			sum += abs(num[i] - num[i + 1]);
		ans = max(ans, sum);
		sum = 0;
	} while (next_permutation(num.begin(), num.end()));
	
	cout << ans;
}