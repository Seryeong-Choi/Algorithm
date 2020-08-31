#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, m, years, nutrient[10][10];
vector<vector<int>> ground(10, vector<int>(10, 5));
deque<int> tree[10][10];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> years;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> nutrient[i][j];

	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		tree[x-1][y-1].push_back(z);
	}

	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			sort(tree[i][j].begin(), tree[i][j].end());
	
	int front, summer;
	deque<int> temp;
	vector<pair<int, int>> pos = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	
	for (int i = 0; i < years; i++) {
		//spring//summer
		vector<pair<int, int>> propa;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if (tree[j][k].size() > 0) {
					temp.clear();
					summer = 0;
					while (!tree[j][k].empty()) {
						front = tree[j][k].front();
						tree[j][k].pop_front();
						if (ground[j][k] >= front) {
							temp.push_back(front + 1);
							if ((front + 1) % 5 == 0)
								propa.push_back({ j,k });
							ground[j][k] -= front;
						}
						else
							summer += front / 2;
					}
					swap(tree[j][k], temp);
					ground[j][k] += summer;
				}
			}
		//fall
		int r, c;
		for (int j = 0; j < propa.size(); j++){
			for (int k = 0; k < 8; k++) {
				r = propa[j].first + pos[k].first;
				c = propa[j].second + pos[k].second;
				if (r >= 0 && r < n && c >= 0 && c < n)
					tree[r][c].push_front(1);
			}
		}
		
		//winter
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				ground[j][k] += nutrient[j][k];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += tree[i][j].size();

	cout << ans;
}