#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, int>> mov = { {0,1}, {1,0}, {0,-1},{-1,0} };
vector<string> board;
int r, c, ans = 1;
vector<bool> chk(26);

void dfs(int x, int y, int cnt) {
	int nx, ny;
	if (cnt > ans)
		ans = cnt;
	for (int i = 0; i < 4; i++) {
		nx = x + mov[i].first;
		ny = y + mov[i].second;
		//cout << nx << ' ' << ny << endl;
		if (nx >= 0 && nx < r && ny >= 0 && ny < c && !chk[board[nx][ny] - 'A']) {
			chk[board[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt+1);
			chk[board[nx][ny] - 'A'] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> str;
		board.push_back(str);
	}
	chk[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans;
}