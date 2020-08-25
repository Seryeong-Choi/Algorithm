#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;
	s1 = ' ' + s1;
	s2 = ' ' + s2;

	int len1 = s1.length(), len2 = s2.length();

	for (int i = 1; i < len1; i++)
		for (int j = 1; j < len2; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

	cout << dp[len1 - 1][len2 - 1];
	
	if (dp[len1 - 1][len2 - 1] != 0) {
		string ans = "";
		int i = len1 - 1, j = len2 - 1;
		int cnt = dp[i][j];
		while (cnt > 0) {
			if (dp[i - 1][j] != cnt && dp[i][j - 1] != cnt) {
				cnt--;
				ans = s1[i] + ans;
				i--;
				j--;
			}
			else if (dp[i - 1][j] == cnt)
				i--;
			else
				j--;
		}
		cout << '\n' << ans;
	}
}