#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct pos {
	int r, c;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	int map[50][50], n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	//solution
	pos move[4] = { {0,-1},{0,1},{-1,0},{1,0} };
	pos now, next;
	int ans = 0;
	bool flag = true;

	while (flag) {
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		flag = false;
		for(int i = 0; i < n ; i++)
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					visited[i][j] = true;
					vector<pos> s;
					vector<pos> ally;
					int sum = 0;
					sum += map[i][j];
					s.push_back({ i,j });
					ally.push_back({ i,j });
					//dfs
					while (!s.empty()) {
						now.r = s.back().r;
						now.c = s.back().c;
						s.pop_back();
						for (pos p : move) {
							next = { now.r + p.r, now.c + p.c };
							if(next.r >= 0 && next.r < n && next.c >= 0 && next.c < n && !visited[next.r][next.c])//index
								if (abs(map[now.r][now.c] - map[next.r][next.c]) >= l && abs(map[now.r][now.c] - map[next.r][next.c]) <= r) {//rule
									visited[next.r][next.c] = true;
									sum += map[next.r][next.c];
									s.push_back({ next.r, next.c });
									ally.push_back({ next.r, next.c });
								}
						}
					}
					//migration
					if (ally.size() > 1) {
						flag = true;
						int mig = sum / ally.size();
						for (pos p : ally)
							map[p.r][p.c] = mig;
					}
				}
			}
		if (flag)
			ans++;
	}
	//output
	cout << ans;
}