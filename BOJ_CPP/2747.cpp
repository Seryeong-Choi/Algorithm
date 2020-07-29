#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo(91, -1);

int solution(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	if (fibo[n] != -1)
		return fibo[n];

	fibo[n] = solution(n - 1) + solution(n - 2);
	return fibo[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	cout << solution(n);
}