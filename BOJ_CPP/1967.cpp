#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> tree[10001]; //pair<node, weight>
int visited[10001] = { 0 };
int dist[10001] = { 0 };
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
	int n;
	cin >> n;

	int t1, t2, t3;
	for (int i = 1 ; i < n; i++) {
		cin >> t1 >> t2 >> t3;
		tree[t1].push_back(make_pair(t2, t3));
		tree[t2].push_back(make_pair(t1, t3));
	}
	for (int i = 1 ; i <= n ; i++)
		sort(tree[i].begin(), tree[i].end());

	bfs(1);
	fill(begin(visited), end(visited), 0);
	bfs(maxIndex);

	cout << dist[maxIndex];
}