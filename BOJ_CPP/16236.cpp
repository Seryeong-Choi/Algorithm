#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct pos {
	int x, y;
};

struct q_data {
	pos p;
	int time;
};

int n, tank[20][20];
pos mov[4] = { {-1,0},{0,-1}, {0,1}, {1,0} };
vector<pos> candidate;
int tx, ty, shark_size = 2;

int bfs(pos now) {
	queue<q_data> q;
	q.push({ now.x, now.y, 0 });
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	visited[now.x][now.y] = true;
	int target = 1000;

	while (!q.empty()) {
		q_data front = q.front();
		q.pop();
		if (front.time < target) {
			for (int i = 0; i < 4; i++) {
				tx = front.p.x + mov[i].x;
				ty = front.p.y + mov[i].y;
				if (tx >= 0 && tx < n && ty >= 0 && ty < n && !visited[tx][ty]) {
					if (tank[tx][ty] > 0 && tank[tx][ty] < shark_size) {
						visited[tx][ty] = true;
						candidate.push_back({ tx,ty });
						target = min(target, front.time + 1);
					}
					else if (tank[tx][ty] == shark_size || tank[tx][ty] == 0){
						visited[tx][ty] = true;
						q.push({ tx,ty,front.time + 1 });
					}
				}
			}
		}
	}
	return target;
}

bool compare(pos a, pos b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

int solution(pos start) {
	int ans = 0;
	pos shark_pos = start;
	int food = 0;
	int time;

	while (true) {
		//bfs
		candidate.clear();
		time = bfs(shark_pos);

		//check candidate
		if (candidate.size() == 0)
			return ans;
		else {
			sort(candidate.begin(), candidate.end(), compare);
			ans += time;
			shark_pos = candidate[0];
			tank[shark_pos.x][shark_pos.y] = 0;
			food++;
			if (food == shark_size) {
				shark_size++;
				food = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	pos start;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> tank[i][j];
			if (tank[i][j] == 9) {
				start = { i,j };
				tank[i][j] = 0;
			}
		}

	cout << solution(start);
}