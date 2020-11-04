#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> child(n + 1);
	vector<int> degree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		child[a].push_back(b);
		degree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if(degree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int front = q.front();
		cout <<	front << ' ' ;
		q.pop();
		for (int i : child[front]) {
			degree[i]--;
			if (degree[i] == 0)
				q.push(i);
		}
	}
}