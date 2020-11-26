#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> p;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b, c, start, end;
	p top;
	cin >> n >> m;
	vector<vector<p>> graph(n + 1);
	vector<int> dist(n + 1, 987654321);
	vector<int> parent(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	cin >> start >> end;

	dist[start] = 0;
	priority_queue<p> pq;
	pq.push({ 0, start });
	while(!pq.empty()){
		top = pq.top();
		pq.pop();
		for (p next : graph[top.second]) {
			if (dist[top.second] + next.second < dist[next.first]) {
				dist[next.first] = dist[top.second] + next.second;
				parent[next.first] = top.second;
				pq.push({ dist[next.first], next.first });
			}
		}
	}
	cout << dist[end] << '\n';
	vector<int> ans;
	while (true) {
		ans.push_back(end);
		if (end == start)
			break;
		end = parent[end];
	}
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0;i--)
		cout << ans[i] << ' ';
}