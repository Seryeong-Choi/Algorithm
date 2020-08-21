#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, mid, target;
vector<int> num;

int binarysearch(int l, int r, int t) {
	if (l > r)
		return 0;
	else {
		mid = (l + r) / 2;
		if (num[mid] == t)
			return 1;
		else if (num[mid] > t)
			return binarysearch(l, mid - 1, t);
		else
			return binarysearch(mid + 1, r, t);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());

	cin >> m;
	//output
	for (int i = 0; i < m; i++) {
		cin >> target;
		cout << binarysearch(0, n - 1, target) << '\n';
	}
}