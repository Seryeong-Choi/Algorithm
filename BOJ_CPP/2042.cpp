#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<long long> segtree;

long long init(int left, int right, int node) {
	if (left == right)
		return segtree[node] = nums[left];
	int mid = (left + right) / 2;
	return segtree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

long long sum(int left, int right, int node, int ql, int qr) {
	if (left > qr || right < ql)
		return 0;
	if (left >= ql && right <= qr)
		return segtree[node];
	int mid = (left + right) / 2;
	return sum(left, mid, node * 2, ql, qr) + sum(mid + 1, right, node * 2 + 1, ql, qr);
}

void update(int left, int right, int node, int target, long long diff) {
	if (left > target || right < target)
		return;

	segtree[node] += diff;

	if (left != right) {
		int mid = (left + right) / 2;
		update(left, mid, node * 2, target, diff);
		update(mid + 1, right, node * 2 + 1, target, diff);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, a, b;
	long long c;
	cin >> n >> m >> k;
	nums.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	//init segtree
	segtree.assign(n * 4, 0);
	init(0, n - 1, 1);

	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - nums[b - 1];
			update(0, n - 1, 1, b - 1, diff);
			nums[b - 1] = c;
		}
		else if (a == 2) {
			cout << sum(0, n - 1, 1, b - 1, c - 1) << '\n';
		}
	}
}