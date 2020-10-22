#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int left = 0;
	int right = 0;
	int sum = 0;
	int ans = 0;
	int mode = 0; //0 : right++ / 1 : left--
	while (left <= right && right < n) {
		if (mode == 0) {
			sum += num[right];
			if (sum < m)
				right++;
			else if (sum >= m) {
				if(sum == m)
					ans++;
				mode = 1;
			}
		}
		else {
			sum -= num[left];
			if (sum > m)
				left++;
			else if (sum <= m) {
				if(sum == m)
					ans++;
				mode = 0;
				right++;
				left++;
			}
		}
	}
	cout << ans;
}