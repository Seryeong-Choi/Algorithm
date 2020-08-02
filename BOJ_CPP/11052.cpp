#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card;
vector<int> dp; //카드 장수, 금액
int solution(int n) {
	if (n == 1)
		return card[1];
	if (dp[n] != -1)
		return dp[n];

	dp[n] = card[n];
	for (int i = 1; i < n; i++)
		dp[n] = max(dp[n], solution(n - i) + card[i]);

	return dp[n];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int temp;
	card.push_back(0);
	for (int i = 0 ; i < n ; i++) {
		cin >> temp;
		card.push_back(temp);
	}

	dp.assign(n + 1, -1);

	cout << solution(n);
}