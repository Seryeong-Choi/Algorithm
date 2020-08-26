#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, mid, input, chk;
vector<int> seq, ans;
vector<pair<int, int>> lis;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	seq.push_back(-1 * 1000000001);

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (seq.back() < input){
			seq.push_back(input);
			lis.push_back({ seq.size() - 1, input });
		}
		else {
			auto it = lower_bound(seq.begin(), seq.end(), input) - seq.begin();
			seq[it] = input;
			lis.push_back({ it, input });
		}
	}

	cout << seq.size() - 1 << '\n';

	chk = seq.size() - 1;
	for (int i = lis.size()-1 ; i >= 0 ; i--)
		if (lis[i].first == chk) {
			ans.push_back(lis[i].second);
			chk--;
		}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
}