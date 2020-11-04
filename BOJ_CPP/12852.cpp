#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(1000001, -1);
int solution(int num) {
	if (dp[num] != -1)
		return dp[num];

	dp[num] = 1 + solution(num - 1);
	if (num % 3 == 0) 
		dp[num] = min(dp[num], 1 + solution(num / 3));
	if (num % 2 == 0) 
		dp[num] = min(dp[num], 1 + solution(num / 2));

	return dp[num];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	cout << solution(n) << '\n';
	
	while (n > 0) {
		cout << n << ' ';
		if (n == 1)
			break;

		if (dp[n - 1] == dp[n] - 1)
			n--;
		else if (n % 2 == 0 && dp[n / 2] == dp[n] - 1)
			n /= 2;
		else if (n % 3 == 0 && dp[n / 3] == dp[n] - 1)
			n /= 3;
	}
}