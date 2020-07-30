#include <iostream>

using namespace std;
int GCD;
int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else
		return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / GCD;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	
	GCD = gcd(a, b);
	cout << GCD << "\n";
	cout << lcm(a, b);
}