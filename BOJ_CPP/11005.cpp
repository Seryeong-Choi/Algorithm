#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, b;
	cin >> n >> b;
	string ans;
	string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int now = 0;
	while (n > 0) {
		now = n % b;
		n /= b;
		if (now >= 10)
			ans = upper[now - 10] + ans;
		else
			ans = to_string(now) + ans;
	}
	cout << ans;
}