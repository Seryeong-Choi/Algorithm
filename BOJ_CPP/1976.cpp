#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
int find(int u) {
	if (u == parent[u])
		return u;
	else
		return parent[u] = find(parent[u]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		parent.push_back(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a;
			if (a == 1) {
				int i_parent = find(i);
				int j_parent = find(j);
				if (i_parent == j_parent)
					continue;
				else if (i_parent < j_parent)
					parent[j_parent] = i_parent;
				else
					parent[i_parent] = j_parent;
			}
		}

	bool flag = true;
	vector<int> route(m);
	for (int i = 0; i < m; i++)
		cin >> route[i];
	for (int i = 1; i < m; i++) {
		if (find(route[i]) != find(route[i - 1])) {
			cout << "NO";
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "YES";
}