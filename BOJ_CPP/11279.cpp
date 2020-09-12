#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, temp;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 0) {
			if (pq.empty())
				cout << '0' << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(temp);
	}
}