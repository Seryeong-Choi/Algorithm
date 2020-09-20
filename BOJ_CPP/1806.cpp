#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
///1806////저장해//////////////일요일///////////
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	int n, s, sum = 0;
	cin >> n >> s;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	if (sum < s)
		cout << "0";
	else if (sum == s)
		cout << n;
	else {
		sum = 0;
		int left = 0;
		int right = 0;
		int ans = 100001;
		bool go_right = true;
		while (left <= right && right < n) {
			if (go_right) {
				sum += num[right];
				if (sum >= s) {
					ans = min(ans, right - left + 1);
					go_right = false;
				}
				else
					right++;
			}
			else {
				sum -= num[left];
				if (sum >= s) {
					ans = min(ans, right - left);
					left++;
				}
				else {
					go_right = true;
					left++;
					right++;
				}
			}
		}
		cout << ans;
	}
}