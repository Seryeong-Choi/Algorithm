#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void membersort();
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	membersort();

	return 0;
}

void membersort() {
	int n = 1;
	cin >> n;

	vector<pair <int, pair<int, string>>> v; //나이, 순번
	int tempI;
	string tempS;

	for (int i = 0; i < n; i++) {
		cin >> tempI;
		cin >> tempS;
		v.push_back(pair<int, pair<int, string>>(tempI, pair<int, string>(i, tempS)));
	}

	sort(v.begin(), v.end());

	cout << v[0].first << " " << v[0].second.second << "\n";
	for (int i = 1; i < n; i++)
		cout << v[i].first << " " << v[i].second.second << "\n";
}