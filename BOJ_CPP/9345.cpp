#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 987654321
#define MIN -987654321
vector<int> dvd, max_seg, min_seg;

int init(vector<int>& seg, int node, int start, int end, bool isMax) {
	if (start > end && isMax)
		return MIN;
	if (start > end && !isMax)
		return MAX;
	if (start == end)
		return seg[node] = dvd[start];

	int mid = (start + end) / 2;
	if(isMax)
		seg[node] = max(init(seg, node * 2, start, mid, isMax), init(seg, node * 2 + 1, mid + 1, end, isMax));
	else
		seg[node] = min(init(seg, node * 2, start, mid, isMax), init(seg, node * 2 + 1, mid + 1, end, isMax));
	return seg[node];
}

void update(vector<int>& seg, int node, int start, int end, int tindex, int tnum, bool isMax) {
	if (start <= tindex && end >= tindex) {
		if (start == end)
			seg[node] = tnum;
		
		else {
			int mid = (start + end) / 2;
			update(seg, node * 2, start, mid, tindex, tnum, isMax);
			update(seg, node * 2 + 1, mid + 1, end, tindex, tnum, isMax);
			if (isMax)
				seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
			else
				seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
		}
	}
}

int query(vector<int>& seg, int node, int start, int end, int ts, int te, bool isMax) {
	if (start > te || end < ts) {
		if (isMax) return MIN;
		else return MAX;
	}
	if (start >= ts && end <= te)
		return seg[node];

	int mid = (start + end) / 2;
	if (isMax)
		return max(query(seg, node * 2, start, mid, ts, te, isMax), query(seg, node * 2 + 1, mid + 1, end, ts, te, isMax));
	else
		return min(query(seg, node * 2, start, mid, ts, te, isMax), query(seg, node * 2 + 1, mid + 1, end, ts, te, isMax));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, a, b, c, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		for (int j = 0; j < n; j++)
			dvd.push_back(j);
		
		min_seg.assign(n * 4, 0);
		max_seg.assign(n * 4, 0);
		init(min_seg, 1, 0, n - 1, false);
		init(max_seg, 1, 0, n - 1, true);

		for(int j = 0; j < k; j++){
			cin >> a >> b >> c;
			if (a == 0) {
				int first_dvd = dvd[b];
				int second_dvd = dvd[c];
				update(min_seg, 1, 0, n - 1, b, second_dvd, false);
				update(min_seg, 1, 0, n - 1, c, first_dvd, false);
				update(max_seg, 1, 0, n - 1, b, second_dvd, true);
				update(max_seg, 1, 0, n - 1, c, first_dvd, true);
				dvd[b] = second_dvd;
				dvd[c] = first_dvd;
			}
			else if (a == 1) {
				if (query(min_seg, 1, 0, n - 1, b, c, false) == b &&
					query(max_seg, 1, 0, n - 1, b, c, true) == c)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
		dvd.clear();
	}
}