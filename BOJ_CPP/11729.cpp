#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int n;
void hanoi(int n, int start, int end, int mid) {
	if (n == 1)
		cout << start << " " << end << "\n";

	else {
		hanoi(n - 1, start, mid, end);
		cout << start << " " << end << "\n";
		hanoi(n - 1, mid, end, start);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n;

	//output
	int ans = pow(2, n) - 1;
	string s = to_string(ans);
	cout << s << "\n";
	hanoi(n, 1, 3, 2);
}