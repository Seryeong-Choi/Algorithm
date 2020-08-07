#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<int> time(200000, -1);
int n, k, now;
deque<int> dq;

void hns() { // 0-1 bfs
	dq.push_front(n);
	time[n] = 0;
	while(!dq.empty()) {
		now = dq.front();
		dq.pop_front();
		if (now < k && time[now * 2] == -1) {
			time[now * 2] = time[now];
			if (now * 2 == k)
				break;
			else
				dq.push_front(now * 2);
		}
		if (now + 1 <= k && time[now + 1] == -1) {
			time[now + 1] = time[now] + 1;
			if (now + 1 == k)
				break;
			else
				dq.push_back(now + 1);
		}
		if (now - 1 >= 0 && time[now - 1] == -1) {
			time[now - 1] = time[now] + 1;
			if (now - 1 == k)
				break;
			else
				dq.push_back(now - 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n >> k;

	hns();
	//output
	cout << time[k];
}