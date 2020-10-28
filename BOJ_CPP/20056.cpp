#include <iostream>
#include <vector>
using namespace std;

struct fireball {
	int m;
	int d;
	int s;
};

struct pos {
	int r;
	int c;
};

vector<pos> mov = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, a, b, c, d, e;
	cin >> n >> m >> k;
	vector<vector<vector<fireball>>> board(n, vector<vector<fireball>>(n));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d >> e;
		board[a - 1][b - 1].push_back({ c,e,d });
	}

	pos new_pos;
	for (int i = 0; i < k; i++) {
		//move
		vector<vector<vector<fireball>>> new_board(n, vector<vector<fireball>>(n));
		for (int j = 0; j < n; j++)
			for (int l = 0; l < n; l++)
				for (fireball ball : board[j][l]) {
					new_pos.r = ((j + mov[ball.d].r * ball.s) % n + n) % n;
					new_pos.c = ((l + mov[ball.d].c * ball.s) % n + n) % n;
					new_board[new_pos.r][new_pos.c].push_back(ball);
				}
			
		board = new_board;
		new_board.clear();
		//check fireballs
		for(int j = 0; j < n; j++)
			for (int l = 0; l < n; l++) {
				if (board[j][l].size() >= 2) {
					int cur_m = 0;
					int cur_s = 0;
					bool odd = false; 
					bool even = false;
					for (fireball ball : board[j][l]) {
						cur_m += ball.m;
						cur_s += ball.s;
						if (ball.d % 2 == 0) even = true;
						else odd = true;
					}
					cur_m /= 5;
					cur_s /= board[j][l].size();
					board[j][l].clear();
					if (cur_m > 0) {
						if (even & odd) { //둘다있으면 1357
							for (int a = 1; a < 9; a += 2)
								board[j][l].push_back({ cur_m, a, cur_s});
						}
						else
							for (int a = 0; a < 8; a += 2)
								board[j][l].push_back({ cur_m, a, cur_s});
					}
				}
			}
	}
	int ans = 0;
	for (int j = 0; j < n; j++)
		for (int l = 0; l < n; l++)
			for (fireball ball : board[j][l])
				ans += ball.m;

	cout << ans;
}