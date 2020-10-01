#include <iostream>
#include <vector>
#include <queue>
#include <set>
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
		vector<set<int>> parent(n);
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
					parent[nxt].insert(cur);
				}
				else if (nxtd == dist[nxt])
					parent[nxt].insert(cur);
			}
		}
		if (dist[d] == 5000000) {
			cout << -1 << '\n';
			continue;
		}
		//delete edge
		vector<bool> visited(n, false);
		queue<int> del;
		del.push(d);
		visited[d] = true;
		while (!del.empty()) {
			cur = del.front();
			del.pop();
			auto it = parent[cur].begin();
			while (it != parent[cur].end()) {
				for (int j = 0; j < graph[*it].size(); j++)
					if (graph[*it][j].first == cur) {
						graph[*it].erase(graph[*it].begin() + j);
						break;
					}
				if (!visited[*it]) {
					visited[*it] = true;
					del.push(*it);
				}
				it++;
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
		dist.clear();
	}
}