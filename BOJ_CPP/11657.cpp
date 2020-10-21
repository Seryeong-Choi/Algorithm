#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<long long>> edge;
	vector<long long> dist(n + 1, 987654321);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back({ a, b, c });
	}

	dist[1] = 0;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[edge[j][0]] != 987654321 && dist[edge[j][0]] + edge[j][2] < dist[edge[j][1]]) {
				if (i == n) // check negative weight cycle
					flag = true;
				else
					dist[edge[j][1]] = dist[edge[j][0]] + edge[j][2];
			}
		}
		if (flag)
			break;
	}

	if (flag)
		cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == 987654321)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}
}