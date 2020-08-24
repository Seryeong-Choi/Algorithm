#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, c, mid, ans = 0;
vector<int> wifi;

void parametric(long long l, long long r) {
	if (l <= r) {
		mid = (l + r) / 2;
		int base = wifi[0], cnt = 1;
		for (int i : wifi)
			if (i >= base + mid) {
				base = i;
				cnt++;
			}

		if (cnt >= c) {
			ans = max(ans, mid);
			parametric(mid + 1, r);
		}
		else
			parametric(l, mid - 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> c;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		wifi.push_back(temp);
	}
	sort(wifi.begin(), wifi.end());

	parametric(1, wifi[n-1]);
	//output
	cout << ans;
}