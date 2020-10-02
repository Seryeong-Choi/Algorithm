#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	vector<int> board(3);
	cin >> n >> board[0] >> board[1] >> board[2];

	vector<int> prev_max = board;
	vector<int> prev_min = board;
	vector<int> nxt(3);

	for (int i = 1; i < n; i++) {
		cin >> board[0] >> board[1] >> board[2];
		//max
		nxt[0] = board[0] + max(prev_max[0], prev_max[1]);
		nxt[1] = board[1] + max(prev_max[0], max(prev_max[1], prev_max[2]));
		nxt[2] = board[2] + max(prev_max[1], prev_max[2]);
		prev_max = nxt;
		//min
		nxt[0] = board[0] + min(prev_min[0], prev_min[1]);
		nxt[1] = board[1] + min(prev_min[0], min(prev_min[1], prev_min[2]));
		nxt[2] = board[2] + min(prev_min[1], prev_min[2]);
		prev_min = nxt;
	}
	cout << *max_element(prev_max.begin(), prev_max.end()) << ' ';
	cout << *min_element(prev_min.begin(), prev_min.end());
}