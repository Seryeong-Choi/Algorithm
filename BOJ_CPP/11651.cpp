#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void coordinates();
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	coordinates();

	return 0;
}

void coordinates() {
	int n = 1;
	cin >> n;

	vector<pair<int, int>> v;
	int input1, input2;

	for (int i = 0; i < n; i++) {
		cin >> input2;
		cin >> input1;
		v.push_back({ input1, input2 });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].second << " " << v[i].first << "\n";
}