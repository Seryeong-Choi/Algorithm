#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> card;
vector<vector<int>> dp; //0: À­ÁÙ¼±ÅÃ 1: ¾Æ·§ÁÙ¼±ÅÃ
int solution(int n, int m) {
	if (n == 0 && m == 0)
		return card[0][0];
	else if (n == 0 && m == 1)
		return card[0][1];
	
	if (n == 1 && m == 0)
		return card[n][m] + solution(n - 1, 1);
	else if (n == 1 && m == 1)
		return card[n][m] + solution(n - 1, 0);


	if (dp[n][m] != -1)
		return dp[n][m];

	if (m == 0)
		dp[n][m] = card[n][m] + max(solution(n - 1, 1), max(solution(n - 2, 0), solution(n - 2, 1)));
	else if (m == 1)
		dp[n][m] = card[n][m] + max(solution(n - 1, 0), max(solution(n - 2, 0), solution(n - 2, 1)));

	return dp[n][m];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	vector<int> ans(t, 0);

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		card.assign(n, vector<int>(2, 0));
		dp.assign(n + 1, vector<int>(2, -1));

		for (int i = 0 ; i < n ; i++)
			cin >> card[i][0];
		for (int i = 0 ; i < n ; i++)
			cin >> card[i][1];

		ans[i] = max(solution(n - 1, 0), solution(n - 1, 1));
	}
	
	for (int i = 0 ; i < t ; i++)
		cout << ans[i] << "\n";
}