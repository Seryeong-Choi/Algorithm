#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int houses[1001][3];

	for (int i = 0; i < n; i++) {
		cin >> houses[i][0];
		cin >> houses[i][1];
		cin >> houses[i][2];
	}

	for (int i = 1; i < n; i++) {
		houses[i][0] = min(houses[i][0] + houses[i-1][1], houses[i][0] + houses[i-1][2]);
		houses[i][1] = min(houses[i][1] + houses[i-1][0], houses[i][1] + houses[i-1][2]);
		houses[i][2] = min(houses[i][2] + houses[i-1][0], houses[i][2] + houses[i-1][1]);
	}

	cout << min(houses[n - 1][0], min(houses[n - 1][1], houses[n - 1][2]));
}