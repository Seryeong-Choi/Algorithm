#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(1001,-1);

int solution(int n){
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	if (dp[n] != -1)
		return dp[n];

	dp[n] = (solution(n - 1) + solution(n - 2)) % 10007;

	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << LLONG_MAX;
}