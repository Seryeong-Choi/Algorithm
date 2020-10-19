#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 987654321;
vector<vector<int>> graph;
vector<vector<int>> chk(16, vector<int>(1 << 16, 987654321));
int dfs(int city, int bit) {
	if (bit == (1 << n) - 1) {
		if (graph[city][0] != 0)
			return graph[city][0];
		else
			return 987654321;
	}
	if (chk[city][bit] != 987654321)
		return chk[city][bit];
	
	for (int i = 0; i < n; i++) {
		if ((bit & (1 << i)) == 0) {
			int new_bit = bit | (1 << i);
			if (graph[city][i] != 0) 
				chk[city][bit] = min(chk[city][bit], dfs(i, new_bit) + graph[city][i]);
		}
	}
	return chk[city][bit];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	graph.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> graph[i][j];

	ans = dfs(0, 1);
	cout << ans;
}