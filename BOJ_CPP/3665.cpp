#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t, m, a, b;
	cin >> t;
	for(int i = 0 ; i < t; i++){
		cin >> n;
		vector<vector<bool>> order(n + 1, vector<bool>(n + 1, false));
		vector<int> rank;
		vector<int> degree(n + 1, 0);
		for (int j = 0; j < n; j++) {
			cin >> a;
			rank.push_back(a);
		}
		for(int j = 0; j < n; j++)
			for (int k = j + 1; k < n; k++) {
				order[rank[j]][rank[k]] = true;
				degree[rank[k]]++;
			}
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			if (order[a][b]) {
				--degree[b];
				++degree[a];
				order[a][b] = false;
				order[b][a] = true;
			}
			else {
				--degree[a];
				++degree[b];
				order[a][b] = true;
				order[b][a] = false;
			}
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (degree[i] == 0)
				q.push(i);
		vector<int> ans;
		while (!q.empty()) {
			int front = q.front();
			q.pop();
			ans.push_back(front);
			for (int j = 1; j <= n; j++) {
				if (order[front][j]) {
					--degree[j];
					if (degree[j] == 0)
						q.push(j);
				}
			}
		}
		if (ans.size() == n)
			for (int j : ans)
				cout << j << ' ';
		else
			cout << "IMPOSSIBLE";
		cout << '\n';
	}
}