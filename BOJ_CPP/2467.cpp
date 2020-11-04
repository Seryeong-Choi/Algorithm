#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> sol(n);
	for (int i = 0; i < n; i++)
		cin >> sol[i];

	int ans = abs(sol[0] + sol[n - 1]);
	vector<int> ans_sol = { 0, n - 1 };
	int start = 0;
	int end = n - 1;
	while (start < end) {
		int cur_sum = sol[start] + sol[end];
		if (abs(cur_sum) < ans) {
			ans = abs(cur_sum);
			ans_sol = { start, end };
		}

		if (cur_sum == 0)
			break;
		else if (cur_sum < 0)
			start++;
		else
			end--;
	}
	
	cout << sol[ans_sol[0]] << ' ' << sol[ans_sol[1]];
}