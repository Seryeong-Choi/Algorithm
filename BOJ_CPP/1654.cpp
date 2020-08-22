#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long k, n, mid, ans = 0;
vector<int> lan;

void parametric(long long l, long long r) {
	if (l > r)
		return;
	else {
		long long num = 0;
		mid = (l + r) / 2;
		
		for (int i = 0; i < k; i++)
			num += lan[i] / mid;
		if (num >= n) {
			ans = max(ans, mid);
			parametric(mid + 1, r);
		}
		else
			parametric(l, mid-1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> k >> n;

	int temp;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		lan.push_back(temp);
	}
	//
	parametric(1, *max_element(lan.begin(), lan.end()));
	//output
	cout << ans;
}