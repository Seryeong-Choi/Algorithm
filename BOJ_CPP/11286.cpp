#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct compare {
	bool operator()(const int& n1, const int& n2) {
		if (abs(n1) == abs(n2))
			return n1 > n2;
		else return abs(n1) > abs(n2);
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, temp;
	cin >> n;
	priority_queue<int, vector<int>, compare> pq;
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