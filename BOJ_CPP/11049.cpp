#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(2));
	vector<vector<int>> dp(n, vector<int>(n, 987654321));
	for (int i = 0; i < n; i++) {
		cin >> matrix[i][0] >> matrix[i][1];
		dp[i][i] = 0;
	}

	for(int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			for (int mid = j; mid < j + i; mid++)
				dp[j][j + i] = min(dp[j][j + i], dp[j][mid] + dp[mid + 1][j + i] + matrix[j][0] * matrix[mid][1] * matrix[j + i][1]);
		
	cout << dp[0][n - 1];
}