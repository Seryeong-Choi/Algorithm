#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[1001];
vector<int> visited;
queue<int> q;

void bfs(int n) {
	q.push(n);
	while (!q.empty()) {
		n = q.front();
		for(int i = 0 ; i < graph[n].size() ; i++)
			if (visited[graph[n][i]] == 0) {
				visited[graph[n][i]] = 1;
				q.push(graph[n][i]);
			}
		q.pop();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	for (int i = 0; i < n + 1; i++)
		sort(graph[i].begin(), graph[i].end());

	int ans = 0;
	visited.assign(n + 1, 0);
	for (int i = 1 ; i < n + 1 ; i++)
		if (visited[i] == 0) {
			bfs(i);
			ans++;
		}

	cout << ans;
}