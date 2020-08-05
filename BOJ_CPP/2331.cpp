#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int p;
int getNext(int n) {
	int temp = 0;
	while (n > 0) {
		temp += pow(n % 10, p);
		n /= 10;
	}
	return temp;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;
	cin >> a >> p;

	vector<pair<int,int>> v(1000000, make_pair(0,0));
	int count = 0;
	int temp = 0;

	while (v[a].first == 0) {
		int next = getNext(a);
		v[a] = make_pair(next, count);
		a = next;
		count++;
	}
	cout << v[a].second;
}