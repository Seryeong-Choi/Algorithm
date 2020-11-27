#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct d {
	int cost;
	int x;
	int y;
};

struct compare {
	bool operator()(d d1, d d2) {
		return d1.cost > d2.cost;
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int k = 1;
	d top;
	vector<vector<int>> mov = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		vector<vector<int>> cave(n, vector<int>(n));
		vector<vector<int>> cost(n, vector<int>(n, 987654321));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> cave[i][j];

		cost[0][0] = cave[0][0];
		priority_queue<d, vector<d>, compare> pq;
		pq.push({ cost[0][0], 0, 0 });
		while (!pq.empty()) {
			top = pq.top();
			pq.pop();
			for (int i = 0; i < 4; i++) {
				d next = { 0, top.x + mov[i][0], top.y + mov[i][1] };
				if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < n) {
					next.cost = top.cost + cave[next.x][next.y];
					if (next.cost < cost[next.x][next.y]) {
						cost[next.x][next.y] = next.cost;
						pq.push(next);
					}
				}
			}
		}
		cout << "Problem " << k << ": " << cost[n - 1][n - 1] << '\n';
		k++;
	}
}