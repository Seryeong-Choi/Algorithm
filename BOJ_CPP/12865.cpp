#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> things;
vector<vector<int>> dp;

int solution(int capacity, int index) { // 가치리턴
	if (index == n)
		return 0;
	if (dp[capacity][index] != -1)
		return dp[capacity][index];

	int max1 = 0;
	//담을때
	if (things[index].first <= capacity) 
		max1 = solution(capacity - things[index].first, index + 1) + things[index].second;
	//안담을때
	int max2 = solution(capacity, index + 1);
	dp[capacity][index] = max(max1, max2);
	return dp[capacity][index];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	int temp1, temp2;
	for (int i = 0; i < n; i++) {
		cin >> temp1;
		cin >> temp2;
		things.push_back(make_pair(temp1, temp2));
	}
	dp.assign(k + 1, vector<int>(n, -1));
	cout << solution(k, 0);
}