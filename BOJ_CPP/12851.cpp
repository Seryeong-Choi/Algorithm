#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> time(200000, -1);
int n, k, now, t;
queue<int> q;
int ans = 0;

void hns() {
	q.push(n);
	time[n] = 0;
	while (!q.empty()) {
		now = q.front();
		q.pop();

		if (now < k) {
			t = now * 2;
			if (time[t] == -1 || time[now] + 1 == time[t]) {
				time[t] = time[now] + 1;
				if (t == k)
					ans++;
				else 
					q.push(t);
			}
		}

		if (now < k) {
			t = now + 1;
			if (time[t] == -1 || time[now] + 1 == time[t]) {
				time[t] = time[now] + 1;
				if (t == k)
					ans++;
				else 
					q.push(t);
			}
		}

		if (now > 0) {
			t = now - 1;
			if (time[t] == -1 || time[now] + 1 == time[t]) {
				time[t] = time[now] + 1;
				if (t == k)
					ans++;
				else 
					q.push(t);
			}
		}
	}
	if (time[k] == 0)
		ans = 1;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n >> k;

	hns();
	//output
	cout << time[k] << "\n";
	cout << ans;
}