#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> time;
	int temp1, temp2;
	for (int i = 0; i < n; i++) {
		cin >> temp1;
		cin >> temp2;
		time.push_back(make_pair(temp1, temp2));
	}

	sort(time.begin(), time.end(), compare);
	
	int ans = 1;
	int end = time[0].second;
	for (int i = 1; i < n; i++) {
		if (time[i].first >= end) {
			end = time[i].second;
			ans++;
		}
	}

	cout << ans;
}