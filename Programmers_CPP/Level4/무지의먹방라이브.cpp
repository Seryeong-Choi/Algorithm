#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
struct compare {
	bool operator()(const p& p1, const p& p2) {
		return p1.first > p2.first;
	}
};

int solution(vector<int> food_times, long long k) {
	long long sum = 0;
	priority_queue<p, vector<p>, compare> pq;

	for (int i = 0; i < food_times.size(); i++) {
		sum += food_times[i];
		pq.push({ food_times[i],i + 1 });
	}
	if (sum <= k)
		return -1;

	long long eaten = 0, now = 0;
	int size = food_times.size();
	vector<int> v;
	p front;
	while (true) {
		front = pq.top();
		now = front.first - eaten;
		if (now == 0)
			size--;
		else if (k - now * size <= 0) {
			while (!pq.empty()) {
				front = pq.top();
				pq.pop();
				v.push_back(front.second);
			}
			break;
		}
		else {
			eaten += now;
			k -= now * size;
			size--;
		}
		pq.pop();
	}
	sort(v.begin(), v.end());
	return v[k % size];
}