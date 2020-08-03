#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> cabbage;
vector<int> pos[4] = { {0,-1},{0,1},{-1,0},{1,0} }; // »óÇÏÁÂ¿ì
int m, n;
queue<pair<int,int>> q;

bool isValid(int x, int y) { //ÀÎµ¦½º Ã¼Å©
	if (x >= 0 && y >= 0 && x < m && y < n) return true;
	else return false;
}

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (cabbage[x][y] == 1) {
			cabbage[x][y] = 0;
			int i, j;
			for (int k = 0; k < 4; k++) {
				i = x + pos[k][0];
				j = y + pos[k][1];
				if (isValid(i,j) && cabbage[i][j] == 1)
					q.push(make_pair(i, j));
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	vector<int> ans;
	int t, k;
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> m >> n >> k;
		cabbage.assign(m, vector<int>(n, 0));
		int temp1, temp2;
		for (int i = 0; i < k; i++) {
			cin >> temp1 >> temp2;
			cabbage[temp1][temp2] = 1;
		}
		int result = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (cabbage[i][j] == 1) {
					bfs(i, j);
					result++;
				}
		ans.push_back(result);
	}
	for (int i = 0; i < t; i++)
		cout << ans[i] << "\n";
}