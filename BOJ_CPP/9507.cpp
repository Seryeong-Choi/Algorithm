#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;
	cin >> t;
	vector<long long> koong(68);
	koong[0] = 1;
	koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;
	for (int i = 4; i <= 67; i++)
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << koong[n] << '\n';
	}
}