#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int e, s, m;
	cin >> e >> s >> m;
	int x = max(e, max(s, m));
	while (true) {
		if ((x - e) % 15 == 0 && (x - s) % 28 == 0 && (x - m) % 19 == 0)
			break;
		x++;
	}
	cout << x;
}