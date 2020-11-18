#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
int ans, n;
void solution(int px, int py, int state) {
	if (px == n - 1 && py == n - 1) {
		ans++;
		return;
	}

	if (state == 0) { // 가로
		if (py + 1 < n && board[px][py + 1] == 0)
			solution(px, py + 1, 0);
		if(px + 1 < n && py + 1 < n && board[px + 1][py + 1] == 0 
			&& board[px][py + 1] == 0 && board[px + 1][py] == 0)
			solution(px + 1, py + 1, 2);
	}
	else if (state == 1) { //세로
		if (px + 1 < n && board[px + 1][py] == 0)
			solution(px + 1, py, 1);
		if (px + 1 < n && py + 1 < n && board[px + 1][py + 1] == 0
			&& board[px][py + 1] == 0 && board[px + 1][py] == 0)
			solution(px + 1, py + 1, 2);
	}
	else { //대각
		if (py + 1 < n && board[px][py + 1] == 0)
			solution(px, py + 1, 0);
		if (px + 1 < n && board[px + 1][py] == 0)
			solution(px + 1, py, 1);
		if (px + 1 < n && py + 1 < n && board[px + 1][py + 1] == 0
			&& board[px][py + 1] == 0 && board[px + 1][py] == 0)
			solution(px + 1, py + 1, 2);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	board.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	solution(0, 1, 0);
	cout << ans;
}