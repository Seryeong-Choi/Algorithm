#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1987654321
#define MIN -1987654321
vector<int> nums, min_seg, max_seg;

int min_init(int node, int start, int end) {
	if (start > end)
		return MAX;
	if (start == end)
		return min_seg[node] = nums[start];

	int mid = (start + end) / 2;
	return min_seg[node] = min(min_init(node * 2, start, mid), 
		min_init(node * 2 + 1, mid + 1, end));
}

int max_init(int node, int start, int end) {
	if (start > end)
		return MIN;
	if (start == end)
		return max_seg[node] = nums[start];

	int mid = (start + end) / 2;
	return max_seg[node] = max(max_init(node * 2, start, mid),
		max_init(node * 2 + 1, mid + 1, end));
}

int find_max(int node, int start, int end, int ts, int te) {
	//cout << start << ' ' << end << endl;
	if (start > te || end < ts)
		return MIN;
	if (start >= ts && end <= te)
		return max_seg[node];

	int mid = (start + end) / 2;
	return max(find_max(node * 2, start, mid, ts, te),
		find_max(node * 2 + 1, mid + 1, end, ts, te));
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
	max_seg.assign(n * 4, 0);
	min_seg.assign(n * 4, 0);
	max_init(1, 1, n);
	min_init(1, 1, n);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << find_min(1, 1, n, a, b) << ' ';
		cout << find_max(1, 1, n, a, b) << '\n';
	}
}