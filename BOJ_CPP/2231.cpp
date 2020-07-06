#include <iostream>
using namespace std;

int solve();
int part(int i);
int main() {

	cout << solve();
	return 0;
}

int solve() {
	int n;
	int result = 0;

	cin >> n;

	for (int i = 1; i < n; i++) {
		if ((i + part(i)) == n) {
			result = i;
			break;
		}
	}
	return result;
}

int part(int i) {
	if (i >= 0 && i <= 9)
		return i;
	else
		return i % 10 + part(i / 10);
}