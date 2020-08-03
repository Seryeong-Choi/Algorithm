#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> table;
vector<int> ps[4] = { {0,-1},{0,1},{-1,0},{1,0} }; // 상하좌우
vector<int> ans;
int n;
int temp;

bool isValid(int x, int y) { //인덱스 체크
	if (x >= 0 && y >= 0 && x < n && y < n) return true;
	else return false;
}

void dfs(int i, int j){
	if (table[i][j] == 1) {
		table[i][j] = 0;
		temp++;
		int x, y;
		for (int k = 0; k < 4; k++) {
			x = i + ps[k][0];
			y = j + ps[k][1];
			if (isValid(x, y) && table[x][y] == 1)
				dfs(x, y);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	string s;
	table.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++)
			table[i][j] = s[j] - '0';
	}

	for (int i = 0 ; i < n ; i++) 
		for (int j = 0; j < n; j++) 
			if (table[i][j] == 1) {
				temp = 0;
				dfs(i, j);
				ans.push_back(temp);
			}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}