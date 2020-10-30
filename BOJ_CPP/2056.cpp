#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;
vector<vector<int>> tasks;
int solution(int index) {
	if (dp[index] != -1)
		return dp[index];
	if (tasks[index][1] == 0)
		return tasks[index][0];

	for (int i = 2; i < tasks[index].size(); i++)
		dp[index] = max(dp[index], solution(tasks[index][i]));
	dp[index] += tasks[index][0];
	return dp[index];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b, c;
	cin >> n;
	dp.assign(n, -1);
	tasks.assign(n, { 0, 0 });
	for (int i = 0; i < n; i++) {
		cin >> tasks[i][0] >> tasks[i][1];
		for (int j = 0; j < tasks[i][1]; j++) {
			cin >> c;
			tasks[i].push_back(c - 1);
		}
	}
	for (int i = 0; i < n; i++) 
		dp[i] = solution(i);
	
	cout << *max_element(dp.begin(), dp.end());
}