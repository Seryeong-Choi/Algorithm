#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[1001];
vector<int> dfsCheck;
vector<int> bfsCheck;
queue<int> q;

void dfs(int n) { 
	cout << n << " ";
	dfsCheck[n] = 1;
	for (int i = 0; i < graph[n].size(); i++)
		if (dfsCheck[graph[n][i]] == 0) {
			dfsCheck[graph[n][i]] = 1;
			dfs(graph[n][i]);
		}
}

void bfs(int n) {
	cout << n << " ";
	bfsCheck[n] = 1;
	q.push(n);

	while (!q.empty()) {
		n = q.front();
		for (int i = 0; i < graph[n].size(); i++)
			if (bfsCheck[graph[n][i]] == 0) {
				q.push(graph[n][i]);
				cout << graph[n][i] << " ";
				bfsCheck[graph[n][i]] = 1;
			}
		q.pop();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, v;
	cin >> n >> m >> v;
	
	dfsCheck.assign(n+1, 0);
	bfsCheck.assign(n+1, 0);

	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	for (int i = 0; i < 1001; i++)
		sort(graph[i].begin(), graph[i].end());
	
	dfs(v);
	cout << "\n";
	bfs(v);
}