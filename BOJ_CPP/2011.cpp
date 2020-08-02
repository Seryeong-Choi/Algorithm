#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool Valid = true;
vector<int> dp;
string s;
int solution(int n) { // 시작 인덱스
	if (n == s.length()-1 && s[n] != '0')
		return 1;
	if (n == s.length()) // n+2 예외처리
		return 1;

	if (dp[n] != -1)
		return dp[n];

	if (s[n] == '1')
		dp[n] = (solution(n + 1) + solution(n + 2)) % 1000000;
	else if (s[n] == '2' && s[n + 1] <= '6')
		dp[n] = (solution(n + 1) + solution(n + 2)) % 1000000;
	else if (s[n] == '0') {
		dp[n] = 0;
		if (n == 0 || (n != 0 && s[n - 1] >= '3'))
			Valid = false;
	}
	else
		dp[n] = solution(n + 1) % 1000000;

	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	dp.assign(s.length(), -1);

	if (Valid == true)
		cout << solution(0);
	else
		cout << 0;
}