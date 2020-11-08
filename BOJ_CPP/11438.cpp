#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m, a, b;
	cin >> n;
	vector<vector<int>> tree(n + 1);
	vector<int> level(n + 1, 0);
	vector<vector<int>> parent(n + 1, vector<int>(18, 0));
	parent[1][0] = 1;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	int front;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int node : tree[front]) {
			if (parent[node][0] == 0) {
				level[node] = level[front] + 1;
				parent[node][0] = front;
				q.push(node);
			}
		}
	}

	for (int i = 1; i < 18; i++)
		for (int j = 1; j <= n; j++)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (level[a] > level[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		int diff = level[b] - level[a];
		for (int j = 0; diff > 0; j++) {
			if (diff % 2 == 1)
				b = parent[b][j];
			diff /= 2;
		}
		if (a == b)
			cout << a << '\n';
		else {
			for(int j = 17; j >= 0; j--) {
				if (parent[a][j] != parent[b][j]) {
					a = parent[a][j];
					b = parent[b][j];
				}
			}
			cout << parent[a][0] << '\n';
		}
	}
}