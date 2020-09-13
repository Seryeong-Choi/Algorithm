#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, a, b, c;
	cin >> n;
	vector<int> room(n);
	for (int i = 0; i < n; i++)
		cin >> room[i];
	cin >> b >> c;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans++;
		if (room[i] - b > 0) {
			ans += (room[i] - b) / c;
			if ((room[i] - b) % c > 0)
				ans++;
		}
	}

	cout << ans;
}