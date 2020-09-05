#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

bool compare(p p1, p p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c, k;
	vector<vector<int>> a(100, vector<int>(100, 0));
	cin >> r >> c >> k;
	r--;
	c--;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];

	int r_size = 3;
	int c_size = 3;
	int ans = 0;
	int new_r_size, new_c_size;
	while (a[r][c] != k) {
		if (ans == 101) {
			ans = -1;
			break;
		}
		if (r_size >= c_size) {
			vector<vector<p>> v(r_size);
			new_c_size = 0;
			for (int i = 0; i < r_size; i++) {
				vector<int> check(101, 0);
				for (int j = 0; j < c_size; j++) {
					if (a[i][j] != 0) {
						check[a[i][j]]++;
						if (check[a[i][j]] == 1)
							v[i].push_back({ a[i][j],0 });
					}
				}
				for (int j = 0; j < v[i].size(); j++)
					v[i][j].second = check[v[i][j].first];
				sort(v[i].begin(), v[i].end(), compare);
				new_c_size = max(new_c_size, (int)v[i].size() * 2);
			}
			c_size = min(100, new_c_size);
			vector<vector<int>> new_a(100, vector<int>(100,0));
			for(int i = 0; i < r_size; i++)
				for (int j = 0; j < c_size / 2; j++) {
					if (j < v[i].size()) {
						new_a[i][2 * j] = v[i][j].first;
						new_a[i][2 * j + 1] = v[i][j].second;
					}
				}
			a = new_a;
		}
		else {
			vector<vector<p>> v(c_size);
			new_r_size = 0;
			for (int j = 0; j < c_size; j++) {
				vector<int> check(101, 0);
				for (int i = 0; i < r_size; i++) {
					if (a[i][j] != 0) {
						check[a[i][j]]++;
						if (check[a[i][j]] == 1)
							v[j].push_back({ a[i][j],0 });
					}
				}
				for (int i = 0; i < v[j].size(); i++)
					v[j][i].second = check[v[j][i].first];
				sort(v[j].begin(), v[j].end(), compare);
				new_r_size = max(new_r_size, (int)v[j].size() * 2);
			}
			r_size = min(100, new_r_size);
			vector<vector<int>> new_a(100, vector<int>(100, 0));
			for (int j = 0; j < c_size; j++)
				for (int i = 0; i < r_size / 2; i++) {
					if (i < v[j].size()) {
						new_a[2 * i][j] = v[j][i].first;
						new_a[2 * i + 1][j] = v[j][i].second;
					}
				}
			a = new_a;
		}
		ans++;
	}
	cout << ans;
}