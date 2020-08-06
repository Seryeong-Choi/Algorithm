#include <iostream>
#include <queue>

using namespace std;

int time[170000] = { 0 };
queue<int> q;
int k;

void bfs(int n) {
	q.push(n);
	time[n] = 0;
	while (n != k) {
		q.pop();
		if (n - 1 >= 0 && time[n - 1] == 0) {
			q.push(n - 1);
			time[n - 1] = time[n] + 1;
		}
		if (n + 1 <= 100000 && time[n + 1] == 0) {
			q.push(n + 1);
			time[n + 1] = time[n] + 1;
		}
		if (2 * n <= 131072 && time[2 * n] == 0) {
			q.push(2 * n);
			time[2 * n] = time[n] + 1;
		}
		n = q.front();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	int n;
	cin >> n >> k;
	
	bfs(n);

	cout << time[k];
}