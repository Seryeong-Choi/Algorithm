#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> time(200001, -1);
	queue<int> q;
	q.push(n);
	time[n] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (front - 1 >= 0 && time[front - 1] == -1) {
			time[front - 1] = time[front] + 1;
			q.push(front - 1);
			if (front - 1 == k)
				break;
		}
		if (front < k) {
			if (time[front + 1] == -1) {
				time[front + 1] = time[front] + 1;
				q.push(front + 1);
				if (front + 1 == k)
					break;
			}
			if (time[front * 2] == -1) {
				time[front * 2] = time[front] + 1;
				q.push(front * 2);
				if (front * 2 == k)
					break;
			}
		}
	}
	cout << time[k] << '\n';
	int now = k;
	vector<int> ans;
	ans.push_back(k);
	while (now != n) {
		if (now - 1 >= 0 && time[now - 1] == time[now] - 1)
			--now;
		else if (time[now + 1] == time[now] - 1)
			++now;
		else
			now /= 2;
		ans.push_back(now);
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
}