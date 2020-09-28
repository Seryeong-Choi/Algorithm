#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<vector<int>> bamboo, dp;
vector<pair<int, int>> mov = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int solution(int x, int y) {
	if (dp[x][y] != -1)
		return dp[x][y];
	
	dp[x][y] = 1;
	int max_next = 0;
	pair<int, int> nxt;
	for (int i = 0; i < 4; i++) {
		nxt = { x + mov[i].first, y + mov[i].second };
		if (nxt.first >= 0 && nxt.first < n && nxt.second >= 0 && nxt.second < n)
			if (bamboo[nxt.first][nxt.second] > bamboo[x][y])
				max_next = max(max_next, solution(nxt.first, nxt.second));
	}
	dp[x][y] += max_next;
	ans = max(ans, dp[x][y]);
	return dp[x][y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	bamboo.assign(n, vector<int>(n));
	dp.assign(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> bamboo[i][j];

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			solution(i, j);

	cout << ans;
}