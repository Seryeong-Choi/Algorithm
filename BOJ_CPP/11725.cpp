#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> tree[100001]; //pair<node, weight>
int visited[100001] = { 0 };
int parent[100001];
queue<int> q;

void bfs(int t) { //bfs
	q.push(t);
	parent[t] = t;
	visited[t] = 1;
	
	while (!q.empty()) {
		t = q.front();
		for(int i = 0 ; i < tree[t].size() ; i++)
			if (visited[tree[t][i]] == 0) {
				visited[tree[t][i]] = 1;
				parent[tree[t][i]] = t;
				q.push(tree[t][i]);
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
	int t1, t2;
	for (int i = 1 ; i < n; i++) {
		cin >> t1 >> t2;
		tree[t1].push_back(t2);
		tree[t2].push_back(t1);
	}

	for (int i = 1; i <= n; i++)
		sort(tree[i].begin(), tree[i].end());

	bfs(1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
}