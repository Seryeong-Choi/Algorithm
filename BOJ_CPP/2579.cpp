#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(301,-1);
vector<int> steps(1,0);
int MAX;

int solution(int n){
	if (n == 0)
		return 0;
	if (n == 1)
		return steps[1];
	if (n == 2)
		return steps[1] + steps[2];

	if (dp[n] != -1)
		return dp[n];

	dp[n] = max(steps[n]+ solution(n - 2), steps[n] + steps[n - 1] + solution(n - 3));
	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> MAX;

	int temp;
	for (int i = 0; i < MAX; i++) {
		cin >> temp;
		steps.push_back(temp);
	}

	cout << solution(MAX);
}