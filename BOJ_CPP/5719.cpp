#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	int n, m, s, d;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cin >> s >> d;
		int u, v, p;
		vector<vector<pi>> graph(n);
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> p;
			graph[u].push_back({ v,p });
		}
		//dijkstra
		priority_queue<pi, vector<pi>, greater<pi>> pq;
		vector<vector<int>> parent(n);
		vector<int> dist(n, 5000000);
		int cur, curd, nxt, nxtd;
		dist[s] = 0;
		pq.push({ dist[s], s });
		while (!pq.empty()) {
			cur = pq.top().second;
			curd = pq.top().first;
			pq.pop();
			for (pi p : graph[cur]) {
				nxt = p.first;
				nxtd = p.second + curd;
				if (nxtd < dist[nxt]) {
					pq.push({ nxtd, nxt });
					dist[nxt] = nxtd;
					//reset parent[nxt]
					parent[nxt].clear();
					parent[nxt].push_back(cur);
				}
				else if (nxtd == dist[nxt])
					parent[nxt].push_back(cur);
			}
		}
		if (dist[d] == 5000000) {
			cout << -1 << '\n';
			continue;
		}
		//delete node
		queue<int> del;
		del.push(d);
		while (!del.empty()) {
			cur = del.front();
			del.pop();
			for (int i = 0; i < parent[cur].size(); i++) {
				nxt = parent[cur][i];
				del.push(nxt);
				for (int j = 0; j < graph[nxt].size(); j++)
					if (graph[nxt][j].first == cur) {
						graph[nxt].erase(graph[nxt].begin() + j);
						break;
					}
			}
		}
		//dijkstra//without tracing
		parent.clear();
		dist.assign(n, 5000000);
		dist[s] = 0;
		pq.push({ dist[s], s });
		while (!pq.empty()) {
			cur = pq.top().second;
			curd = pq.top().first;
			pq.pop();
			for (pi p : graph[cur]) {
				nxt = p.first;
				nxtd = p.second + curd;
				if (nxtd < dist[nxt]) {
					pq.push({ nxtd, nxt });
					dist[nxt] = nxtd;
				}
			}
		}
		if (dist[d] == 5000000) 
			cout << -1 << '\n';
		else
			cout << dist[d] << '\n';
	}
}