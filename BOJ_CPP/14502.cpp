#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pos;
int n, m, x, y, tx, ty, map[8][8], tmap[8][8], ans = 0, temp;
pos p[4] = { {-1,0},{1,0},{0,-1},{0,1} };
queue<pos> q;
vector<pos> zero, virus;

void bfs() {
	for (pos s : virus)
		q.push(s);

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			tx = x + p[i].first;
			ty = y + p[i].second;
			if (tx >= 0 && tx < n && ty >= 0 && ty < m)
				if (tmap[tx][ty] == 0) {
					tmap[tx][ty] = 2;
					q.push({ tx, ty });
				}
		}
	}
}

void copy_map() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmap[i][j] = map[i][j];
}

int get_sum() {
	temp = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (tmap[i][j] == 0)
				temp++;
	
	return temp;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				zero.push_back({ i,j });
			else if (map[i][j] == 2)
				virus.push_back({ i,j });
		}
	
	for (int i = 0 ; i < zero.size() - 2; i++) {
		for (int j = i+1; j < zero.size() - 1; j++) {
			for (int k = j+1; k < zero.size(); k++) {
				copy_map();
				tmap[zero[i].first][zero[i].second] = 1;
				tmap[zero[j].first][zero[j].second] = 1;
				tmap[zero[k].first][zero[k].second] = 1;
				bfs();
				ans = max(ans, get_sum());
			}
		}
	}

	cout << ans;
}
