#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1987654321
vector<int> nums, min_seg;

int init(int node, int start, int end) {
	if (start > end)
		return MAX;
	if (start == end)
		return min_seg[node] = nums[start];

	int mid = (start + end) / 2;
	return min_seg[node] = min(init(node * 2, start, mid),
		init(node * 2 + 1, mid + 1, end));
}

int find_min(int node, int start, int end, int ts, int te) {
	if (start > te || end < ts)
		return MAX;
	if (start >= ts && end <= te)
		return min_seg[node];

	int mid = (start + end) / 2;
	return min(find_min(node * 2, start, mid, ts, te),
		find_min(node * 2 + 1, mid + 1, end, ts, te));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b;
	cin >> n >> m;
	nums.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}
	min_seg.assign(n * 4, 0);
	init(1, 1, n);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << find_min(1, 1, n, a, b) << ' ';
	}
}