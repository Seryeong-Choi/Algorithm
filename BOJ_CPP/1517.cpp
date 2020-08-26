#include <iostream>
#include <vector>
using namespace std;

int n, lcur, rcur, tcur;
long long ans;
vector<int> num, t(500000);

void merge(int l, int r) {
	int mid = (l + r) / 2;
	lcur = l;
	rcur = mid + 1;
	tcur = l;

	while (lcur <= mid && rcur <= r) {
		if (num[lcur] <= num[rcur])
			t[tcur++] = num[lcur++];
		else {
			ans += rcur - tcur;
			t[tcur++] = num[rcur++];
		}
	}
	if (lcur > mid)
		while (rcur <= r)
			t[tcur++] = num[rcur++];
	else
		while (lcur < mid + 1)
			t[tcur++] = num[lcur++];

	for (int i = l; i <= r; i++)
		num[i] = t[i];
}

void mergeSort(int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l, r);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		num.push_back(temp);
	}

	mergeSort(0, n - 1);

	cout << ans;
}