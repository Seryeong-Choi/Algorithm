#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[101][101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	s3 = ' ' + s3;

	int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

	for (int i = 1; i < len1; i++)
		for (int j = 1; j < len2; j++)
			for(int k = 1; k < len3; k++){
				if (s1[i] == s2[j] && s1[i] == s3[k])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k-1]));
		}

	
	cout << dp[len1 - 1][len2 - 1][len3 - 1];
}