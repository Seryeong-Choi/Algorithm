#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<int>> graph, ans;
vector<int> parent, visited;
stack<int> s;
int cnt = 0;

int dfs(int vertex) {
	s.push(vertex);
	parent[vertex] = ++cnt;
	int p = parent[vertex];
	for (int nxt : graph[vertex]) {
		if (parent[nxt] == 0)
			p = min(p, dfs(nxt));
		else if (visited[nxt] == 0)
			p = min(p, parent[nxt]);
	}
	if (p == parent[vertex]) {
		vector<int> temp;
		while (true) {
			int top = s.top();
			temp.push_back(top);
			visited[top] = 1;
			s.pop();
			if (top == vertex)
				break;
		}
		sort(temp.begin(), temp.end());
		ans.push_back(temp);
		///return;
	}
	return p;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e, a, b;
	cin >> v >> e;
	graph.assign(v + 1, vector<int>());
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	parent.assign(v + 1, 0);
	visited.assign(v + 1, 0);
	for (int i = 1; i <= v; i++)
		if (parent[i] == 0)
			dfs(i);

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (vector<int> vec : ans) {
		for (int i : vec)
			cout << i << ' ';
		cout << -1 << '\n';
	}
}