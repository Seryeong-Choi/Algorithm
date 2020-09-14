#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, t1;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	
	pq1.push(-11111);
	pq2.push(11111);
	for (int i = 0; i < n; i++) {
		cin >> t1;
		if (pq1.size() < pq2.size()) {
			if (t1 <= pq2.top()) {
				pq1.push(t1);
				cout << pq1.top() << '\n';
			}
			else {
				pq2.push(t1);
				t1 = pq2.top();
				pq2.pop();
				pq1.push(t1);
				cout << pq1.top() << '\n';
			}
		}
		else if(pq1.size() == pq2.size()){
			if (t1 <= pq1.top()) {
				pq1.push(t1);
				cout << pq1.top() << '\n';
			}
			else {
				pq2.push(t1);
				cout << pq2.top() << '\n';
			}
		}
		else {
			if (t1 <= pq2.top() && pq1.top() <= t1 || t1 > pq2.top()) {
				pq2.push(t1);
				cout << pq1.top() << '\n';
			}
			else {
				pq1.push(t1);
				t1 = pq1.top();
				pq1.pop();
				pq2.push(t1);
				cout << pq1.top() << '\n';
			}
		}
	}
}