#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, a, prev;
	cin >> n >> m;
	vector<vector<int>> child(n + 1);
	vector<int> degree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> k;
		int now_deg = 1;
		for (int j = 0; j < k; j++) {
			cin >> a;
			if (j > 0) {
				child[prev].push_back(a);
				degree[a]++;
			}
			prev = a;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (degree[i] == 0)
			q.push(i);
	vector<int> ans;
	while (!q.empty()) {
		int	front = q.front();
		q.pop();
		ans.push_back(front);
		for (int i : child[front]) {
			degree[i]--;
			if (degree[i] == 0)
				q.push(i);
		}
	}

	if (ans.size() == n) {
		for (int i : ans)
			cout << i << '\n';
	}
	else cout << 0;
}