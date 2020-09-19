#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, k, w;
vector<vector<int>> graph;
vector<int> time, dp;

int solution(int index) {
	if (dp[index] != -1)
		return dp[index];
	
	dp[index] = 0;
	for (int i : graph[index]) {
		dp[index] = max(dp[index], solution(i));
	}
	dp[index] += time[index];
	return dp[index];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		int t1, t2;
		time.assign(n + 1, 0);
		dp.assign(n + 1, -1);
		graph.assign(n + 1, vector<int>());
		for (int j =1; j <= n; j++)
			cin >> time[j];
		for (int j = 0; j < k; j++) {
			cin >> t1 >> t2;
			graph[t2].push_back(t1);
		}
		cin >> w;
		cout << solution(w) << '\n';
	}
}