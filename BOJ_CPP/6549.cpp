#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1987654321
vector<int> histo, segtree; //ÀÎµ¦½ºÀúÀå

long long init(int node, int start, int end) {
	if (start > end)
		return MAX;
	if (start == end)
		return segtree[node] = start;

	int mid = (start + end) / 2;
	int left_index = init(node * 2, start, mid);
	int right_index = init(node * 2 + 1, mid + 1, end);
	if (histo[left_index] < histo[right_index])
		segtree[node] = left_index;
	else
		segtree[node] = right_index;
	return segtree[node];
}

int query(int node, int start, int end, int ts, int te) {
	if (start > te || end < ts)
		return 0;
	if (start >= ts && end <= te)
		return segtree[node];

	int mid = (start + end) / 2;
	int left_index = query(node * 2, start, mid, ts, te);
	int right_index = query(node * 2 + 1, mid + 1, end, ts, te);
	if (histo[left_index] < histo[right_index])
		return left_index;
	else
		return right_index;
}

long long find(int start, int end, int n) {
	if (start > end)
		return -1;

	int mid = query(1, 1, n, start, end);
	long long ans = max(ans, (long long)histo[mid] * (end - start + 1));
	ans = max(ans, max(find(start, mid - 1, n), find(mid + 1, end, n)));
	return ans;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		histo.push_back(0);
		for (int i = 0; i < n; i++) {
			cin >> a;
			histo.push_back(a);
		}
		segtree.assign(n * 4, 0);
		init(1, 1, n);
		histo[0] = MAX;
		cout << find(1, n, n) << '\n';

		segtree.clear();
		histo.clear();
	}
}