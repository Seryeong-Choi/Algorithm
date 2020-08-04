#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> visited;
vector<int> color; // 0:»ö¾øÀ½ 1:»¡°­ 2:ÆÄ¶û

int getColor(int parent) {
	if (color[parent] == 1)
		return 2;
	else
		return 1;
}

void coloring(int n, vector<int> graph[]) { //dfs
	for(int i = 0 ; i < graph[n].size() ; i++)
		if (visited[graph[n][i]] == 0) {
			visited[graph[n][i]] = 1;
			color[graph[n][i]] = getColor(n);
			coloring(graph[n][i], graph);
		}
}

bool check(int n, vector<int> graph[]) {
	int c = color[n];
	for (int i = 0 ; i < graph[n].size() ; i++)
		if (color[graph[n][i]] == c)
			return false;
	
	return true;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int v, e;
		cin >> v >> e;
		
		vector<int> graph[20001];
		int t1, t2;
		for (int j = 0; j < e; j++) {
			cin >> t1 >> t2;
			graph[t1].push_back(t2);
			graph[t2].push_back(t1);
		}

		visited.assign(v + 1, 0);
		color.assign(v + 1, 0);
		for (int j = 1 ; j < v + 1 ; j++)
			sort(graph[j].begin(), graph[j].end());
		
		bool ans = true;
		for (int j = 1 ; j < v + 1 ; j++)
			if (visited[j] == 0) {
				color[j] = 1;
				visited[j] = 1;
				coloring(j, graph);
			}

		for(int j = 1 ; j < v + 1 ; j++)
			if (check(j, graph) == false) {
				ans = false;
				break;
			}
			
		if (ans == true) cout << "YES\n";
		else cout << "NO\n";
	}
}