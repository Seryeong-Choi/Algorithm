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
	vector<int> parent(n + 1, 0);
	parent[1] = 1;
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
			if (parent[node] == 0) {
				level[node] = level[front] + 1;
				parent[node] = front;
				q.push(node);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (level[a] > level[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		while (level[a] < level[b]) {
			b = parent[b];
		}
		if (a == b)
			cout << a << '\n';
		else {
			while (true) {
				a = parent[a];
				b = parent[b];
				if (a == b) {
					cout << a << '\n';
					break;
				}
			}			
		}
	}
}