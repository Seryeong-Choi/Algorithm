#include <iostream>
#include <vector>
using namespace std;

long long n;
typedef vector<vector<long long>> matrix;
vector<int> fibo = { 0,1 };//fibo[0], fibo[1];
matrix base = { {1,1}, {1,0} };
matrix result;
const int mod = 1000000;

matrix daq(long long index) {
	if (index == 1)
		return base;

	else if (index % 2 == 0) {
		matrix m = daq(index / 2);
		result.assign(2, vector<long long>(2, 0));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int a = 0; a < 2; a++) {
					result[i][j] += (m[i][a] % mod) * (m[a][j] % mod);
					result[i][j] %= mod;
				}
		return result;
	}

	else {
		matrix m = daq(index - 1);
		result.assign(2, vector<long long>(2, 0));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int a = 0; a < 2; a++) {
					result[i][j] += (m[i][a] % mod * base[a][j] % mod);
					result[i][j] %= mod;
				}
		return result;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n;
	//fibo	//output
	if (n == 1)
		cout << 1;
	else {
		result = daq(n - 1);
		cout << result[0][0];
	}
}