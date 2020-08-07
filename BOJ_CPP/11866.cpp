#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> v;

void josephus() {
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	
	cout << '<';
	int pos = 0;
	for(int i = 0 ; i < n-1; i++) {
		pos = (pos + k - 1) % v.size();
		cout << v[pos] << ", ";
		v.erase(v.begin() + pos);
	}
	cout << v[0] << '>';
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n >> k;
	//output
	josephus();
}