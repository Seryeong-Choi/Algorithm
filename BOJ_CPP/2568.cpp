#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, a, b;
	cin >> n;
	vector<int> lines(500001, -1);
	vector<int> lis;
	vector<pair<int, int>> track;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		lines[a] = b;
	}

	lis.push_back(-987654321);
	for (int i = 1; i <= 500000; i++) {
		if (lines[i] != -1) {
			if (lines[i] > lis.back()) {
				lis.push_back(lines[i]);
				track.push_back({ lis.size() - 1, i });
			}
			else {
				auto it = lower_bound(lis.begin(), lis.end(), lines[i]);
				*it = lines[i];
				track.push_back({ it - lis.begin(), i });
			}
		}
	}

	int target = lis.size() - 1;
	vector<int> ans;
	for (int i = track.size() - 1; i >= 0; i--) {
		if (target < 0)
			break;
		if (track[i].first == target)
			target--;
		else
			ans.push_back(track[i].second);
	}
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << '\n';
}