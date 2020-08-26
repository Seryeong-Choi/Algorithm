#include <iostream>
#include <algorithm>

using namespace std;

int n, num[500000], m, mid, target;

void binary(int l, int r, int t) {
	if (l > r)
		cout << "0 ";

	else {
		mid = (l + r) / 2;
		if (num[mid] == t)
			cout << "1 ";
		else if (num[mid] < t)
			binary(mid + 1, r, t);
		else
			binary(l, mid - 1, t);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> target;
		binary(0, n - 1, target);
	}
}