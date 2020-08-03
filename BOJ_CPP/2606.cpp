#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

vector<int> graph[1001];
vector<int> bfsCheck;
queue<int> q;

void bfs(int n) {
	q.push(n);
	bfsCheck[n] = 1;
	while (!q.empty()) {
		n = q.front();
		q.pop();
		for (int i = 0 ; i < graph[n].size() ; i++)
			if (bfsCheck[graph[n][i]] == 0) {
				bfsCheck[graph[n][i]] = 1;
				q.push(graph[n][i]);
			}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	bfsCheck.assign(n+1, 0);

	int temp1, temp2;
	for (int i = 0 ; i < m ; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	for (int i = 0; i < 1001; i++)
		sort(graph[i].begin(), graph[i].end());
	
	bfs(1);

	cout << accumulate(bfsCheck.begin(), bfsCheck.end(), 0) - 1;
}