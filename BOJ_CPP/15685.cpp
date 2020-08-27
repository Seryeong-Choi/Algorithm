#include <iostream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;
struct pos {
	int x, y;
};
int n;
bool chk[101][101];

pos draw(vector<int> dir, int x, int y) {
	for (int i = 0; i < dir.size(); i++) {
		if (dir[i] == 0) {
			x++;
			chk[x][y] = true;
		}
		else if (dir[i] == 1) {
			y--;
			chk[x][y] = true;
		}
		else if (dir[i] == 2) {
			x--;
			chk[x][y] = true;
		}
		else {
			y++;
			chk[x][y] = true;
		}
	}
	return { x,y };
}

void dragon(int x, int y, int first_dir, int gen) {
	vector<int> dir = { first_dir };
	pos p = { x,y };
	chk[x][y] = true;

	p = draw(dir, p.x, p.y);

	for (int i = 0; i < gen; i++) {
		vector<int> now;
		for (int j = pow(2,i) - 1 ; j >= 0 ; j--) {
			now.push_back((dir[j] + 1) % 4);
			dir.push_back((dir[j] + 1) % 4);
		}
		p = draw(now, p.x, p.y);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int x, y, d, g;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		dragon(x, y, d, g);
	}

	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (chk[i][j] && chk[i + 1][j] && chk[i][j + 1] && chk[i + 1][j + 1])
				ans++;

	cout << ans;
}