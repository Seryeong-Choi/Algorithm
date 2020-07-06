#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void wordsort();
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	wordsort();

	return 0;
}

void wordsort() {
	int n = 1;
	cin >> n;

	vector<pair <int, string>> v;
	string temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back({ temp.length(), temp });
	}

	sort(v.begin(), v.end());

	cout << v[0].second << "\n";
	for (int i = 1; i < n; i++)
		if (v[i].second != v[i - 1].second)
			cout << v[i].second << "\n";
}