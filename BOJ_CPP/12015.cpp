#include <iostream>
#include <vector>
using namespace std;

int n, temp, mid, lowerBound;
vector<int> num, ans;

int binarySearch(int l, int r, int t) {

	while (r >= l) {
		mid = (l + r) / 2;
		if (ans[mid] > t)
			r = mid - 1;
		else if (ans[mid] == t)
			return mid;
		else
			l = mid + 1;
	}
	return l;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n;

	num.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	//lis
	ans.push_back(num[0]);
	for (int i = 1; i < n; i++) {
		if (num[i] > ans.back())
			ans.push_back(num[i]);
		else {
			lowerBound = binarySearch(0, ans.size() - 1, num[i]);
			ans[lowerBound] = num[i];
		}
	}
	//output
	cout << ans.size();
}