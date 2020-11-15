#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a;
	cin >> n;
	vector<int> degree(n + 1, 0);
	vector<int> time(n + 1, 0);
	vector<int> total_time(n + 1, 0);
	vector<vector<int>> children(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		time[i] = a;
		while (true) {
			cin >> a;
			if (a == -1)
				break;
			else {
				++degree[i];
				children[a].push_back(i);
			}
		}
	}
	queue<int> q;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (degree[i] == 0) {
			q.push(i);
			total_time[i] += time[i];
		}
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i : children[front]) {
			degree[i]--;
			total_time[i] = max(total_time[front] + time[i], total_time[i]);
			if (degree[i] == 0)
				q.push(i);
			
		}
	}
	for (int i = 1; i <= n; i++)
		cout << total_time[i] << '\n';
}