#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> tree[100001]; //pair<node, distance>
int visited[100001] = { 0 };
int dist[100001] = { 0 };
queue<int> q;
int maxIndex = 1;

void bfs(int t) { //bfs
	q.push(t);
	visited[t] = 1;
	dist[t] = 0;

	while (!q.empty()) {
		t = q.front();
		for(int i = 0 ; i < tree[t].size() ; i++)
			if (visited[tree[t][i].first] == 0) {
				visited[tree[t][i].first] = 1;
				dist[tree[t][i].first] = dist[t] + tree[t][i].second;
				if (dist[maxIndex] < dist[tree[t][i].first])
					maxIndex = tree[t][i].first;
				q.push(tree[t][i].first);
			}
		q.pop();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	int v;
	cin >> v;

	int j, t1, t2;
	for (int i = 1; i <= v; i++) {
		cin >> j;
		while (true) {
			cin >> t1;
			if (t1 == -1)
				break;
			cin >> t2;
			tree[j].push_back(make_pair(t1, t2));
		}
	}
	for (int i = 1; i <= v; i++)
		sort(tree[i].begin(), tree[i].end());
	//bfs
	bfs(1);
	fill(begin(visited), end(visited), 0);
	bfs(maxIndex);
	//output
	cout << dist[maxIndex];
}