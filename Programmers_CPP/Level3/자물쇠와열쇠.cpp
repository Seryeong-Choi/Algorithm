#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct pos {
	int x, y;
};

pos getMinPos(vector<pos> v) {
	int min_x = 100, min_y = 100;
	for (int i = 0; i < v.size(); i++) {
		min_x = min(v[i].x, min_x);
		min_y = min(v[i].y, min_y);
	}
	return { min_x, min_y };
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	//generate key
	int m = key.size();
	int n = lock.size();

	vector<pos> r_keys[4];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if (key[i][j] == 1)
				r_keys[0].push_back({ i,j });

	for (int i = 0; i < r_keys[0].size(); i++) {
		r_keys[1].push_back({ r_keys[0][i].y, -1 * r_keys[0][i].x });
		r_keys[2].push_back({ -1 * r_keys[0][i].x, -1 * r_keys[0][i].y });
		r_keys[3].push_back({ -1 * r_keys[0][i].y, r_keys[0][i].x });
	}

	for (int i = 0; i < 4; i++) {
		pos m = getMinPos(r_keys[i]);
		for (int j = 0; j < r_keys[0].size(); j++) {
			r_keys[i][j].x -= m.x;
			r_keys[i][j].y -= m.y;
		}
	}

	//check lock
	int lock_count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (lock[i][j] == 0)
				lock_count++;
	if (r_keys[0].size() < lock_count)
		return false;

	//check every possible position
	pos cur;
	int count;
	for (int i = 0; i < 4; i++)
		for (int j = -m; j < n; j++)
			for (int k = -m; k < n; k++) {
				count = 0;
				for (int l = 0; l < r_keys[i].size(); l++) {
					cur.x = r_keys[i][l].x + j;
					cur.y = r_keys[i][l].y + k;
					if (cur.x >= 0 && cur.x < n && cur.y >= 0 && cur.y < n) {
						if (lock[cur.x][cur.y] == 1) {
							count = 0;
							break;
						}
						else
							count++;
					}
				}
				if (count == lock_count)
					return true;
			}

	return false;
}