#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> time(n, 0);
	for (int i = 0; i < n; i++)
		cin >> time[i];
	sort(time.begin(), time.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += time[i] * (n - i);
	}

	cout << ans;
}