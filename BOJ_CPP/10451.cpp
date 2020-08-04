#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> visited;

void dfs(int n, vector<int> graph[]) {
	for(int i = 0 ; i < graph[n].size() ; i++)
		if (visited[graph[n][i]] == 0) {
			visited[graph[n][i]] = 1;
			dfs(graph[n][i], graph);
		}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<int> graph[1001];
		int t1;
		for (int j = 1; j <= n; j++) {
			cin >> t1;
			graph[j].push_back(t1);
			graph[t1].push_back(j);
		}
		
		for (int j = 1; j < n + 1; j++)
			sort(graph[j].begin(), graph[j].end());

		visited.assign(n + 1, 0);
		int ans = 0;
		for (int j = 1; j < n + 1; j++)
			if (visited[j] == 0) {
				visited[j] = 1;
				dfs(j, graph);
				ans++;
			}
		cout << ans << "\n";
	}
}