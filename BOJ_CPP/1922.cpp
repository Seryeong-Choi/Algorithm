#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent, level(1001, 0);
vector<vector<int>> cost;

int find(int u) {
	if (u == parent[u])
		return u;
	else
		return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	if (level[u] < level[v])
		parent[u] = v;
	else {
		parent[v] = u;
		if (level[v] == level[u])
			++level[u];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b, c;
	cin >> n >> m;

	for (int i = 0; i < 1001; i++)
		parent.push_back(i);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		cost.push_back({ c,a,b });
	}
	sort(cost.begin(), cost.end());
	int ans = 0;
	for (vector<int> v : cost) {
		int first = find(v[1]);
		int second = find(v[2]);
		if (first == second)
			continue;
		else {
			merge(first, second);
			ans += v[0];
		}
	}
	cout << ans;
}