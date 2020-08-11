#include <iostream>
using namespace std;

const int p = 1000000007;
int n, k; //n^2 범위 long long // n^2 %p 범위 int
long long a = 1, b = 1;

long long dac(long long a, long long b) {
	if (b == 1)
		return a;
	else if (b % 2 == 0)
		return (dac(a, b / 2) * dac(a, b / 2)) % p;
	else
		return (a * dac(a, b - 1)) % p;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n >> k;
	//
	for (int i = 1 ; i <= n ; i++)
		a = a * i % p;
	for (int i = 1 ; i <= k ; i++)
		b = b * i % p;
	for (int i = 1 ; i <= n - k ; i++)
		b = b * i % p;
	//output
	b = dac(b, p - 2) % p;
	b = a * b % p;
	cout << b;
}