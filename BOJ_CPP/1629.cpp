#include <iostream>
using namespace std;

long long pow(long long a, long long b, long long c) {
	if (b == 1)
		return a % c;
	else if (b % 2 == 0) {
		long long temp = pow(a % c, b / 2, c) % c;
		return temp * temp % c;
	}
	else
		return (a % c) * pow(a % c, b - 1, c) % c;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	long long a, b, c;
	cin >> a >> b >> c;
	
	cout << pow(a, b, c);
}