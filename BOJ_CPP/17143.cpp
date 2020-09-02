#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
	int r, c, s, d, z;
};
int r, c, m;
vector<Shark> shark;

vector<int> top_down(Shark s) {
	int move;
	while (true) {
		if (s.d == 1) {
			move = s.r;
			if (move < s.s) {
				s.r -= move;
				s.s -= move;
				s.d = 2;
			}
			else {
				s.r -= s.s;
				break;
			}
		}
		else {
			move = r - 1 - s.r;
			if (move < s.s) {
				s.r += move;
				s.s -= move;
				s.d = 1;
			}
			else {
				s.r += s.s;
				break;
			}
		}
	}
	return{ s.r, s.d };
}

vector<int> left_right(Shark s) {
	int move;
	while (true) {
		if (s.d == 4) {
			move = s.c;
			if (move < s.s) {
				s.c -= move;
				s.s -= move;
				s.d = 3;
			}
			else {
				s.c -= s.s;
				break;
			}
		}
		else {
			move = c - 1 - s.c;
			if (move < s.s) {
				s.c += move;
				s.s -= move;
				s.d = 4;
			}
			else {
				s.c += s.s;
				break;
			}
		}
	}
	return{ s.c, s.d };
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> m;
	int x, y, s, d, z;
	vector<vector<int>> ground(r, vector<int>(c, -1)); //상어 인덱스!!기록
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> s >> d >> z;
		if (d == 1 || d == 2)
			s %= (r - 1) * 2;
		else
			s %= (c - 1) * 2;
		shark.push_back({ x-1,y-1,s,d,z });
		ground[x - 1][y - 1] = i;
	}

	int ans = 0;
	vector<bool> catched(m, false);
	vector<int> temp;

	for (int i = 0; i < c; i++) {
		//fishing
		for (int j = 0; j < r; j++) {
			if (ground[j][i] >= 0) {
				ans += shark[ground[j][i]].z;
				catched[ground[j][i]] = true;
				break;
			}
		}

		//move
		vector<vector<int>> new_ground(r, vector<int>(c, -1));
		for (int j = 0; j < shark.size(); j++) {
			if (!catched[j]) {
				if (shark[j].d == 1 || shark[j].d == 2) {
					temp = top_down(shark[j]);
					shark[j].r = temp[0];
					shark[j].d = temp[1];
				}
				else {
					temp = left_right(shark[j]);
					shark[j].c = temp[0];
					shark[j].d = temp[1];
				}

				if (new_ground[shark[j].r][shark[j].c] >= 0) {
					if (shark[new_ground[shark[j].r][shark[j].c]].z < shark[j].z) {
						catched[new_ground[shark[j].r][shark[j].c]] = true;
						new_ground[shark[j].r][shark[j].c] = j;
					}
					else {
						catched[j] = true;
					}
				}
				else {
					new_ground[shark[j].r][shark[j].c] = j;
				}
			}
		}
		ground = new_ground;
	}
	cout << ans;
}