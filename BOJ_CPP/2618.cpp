#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct pos {
	int r;
	int c;
};

vector<vector<int>> dp(1002, vector<int>(1002, -1));
vector<pos> cases(1002);
vector<vector<int>> path(1002, vector<int>(1002, 0));
int n, w;

int solution(int x, int y) {
	if (dp[x][y] != -1)
		return dp[x][y];

	if (x == w + 1 || y == w + 1)
		return 0;

	int next = max(x, y) + 1;
	int first = solution(next, y) + abs(cases[x].r - cases[next].r) + abs(cases[x].c - cases[next].c);
	int second = solution(x, next) + abs(cases[y].r - cases[next].r) + abs(cases[y].c - cases[next].c);
	if (first > second) {
		path[x][y] = 2;
		dp[x][y] = second;
	}
	else {
		path[x][y] = 1;
		dp[x][y] = first;
	}
	return dp[x][y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y;
	cin >> n >> w;
	cases[0] = { 1, 1 };
	cases[1] = { n, n };
	for (int i = 2; i <= w + 1; i++) {
		cin >> x >> y;
		cases[i] = { x, y };
	}
	
	cout << solution(0, 1) << '\n';
	x = 0;
	y = 1;
	while (x != w + 1 && y != w + 1) {
		cout << path[x][y] << '\n';
		int next = max(x, y) + 1;
		if (path[x][y] == 1)
			x = next;
		else 
			y = next;
	}
}