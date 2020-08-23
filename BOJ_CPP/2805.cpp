#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, m, mid, ans = 0;
vector<long long> tree;

void parametric(long long l, long long r) {
	if (l > r)
		return;
	else {
		mid = (l + r) / 2;

		long long len = 0;
		for (int i = 0; i < n; i++)
			if (tree[i] >= mid)
				len += tree[i] - mid;

		if (len >= m) {
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
	cin >> n >> m;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		tree.push_back(temp);
	}
	//
	parametric(0, *max_element(tree.begin(), tree.end()));
	//output
	cout << ans;
}