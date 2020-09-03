#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct pos {
	int x, y;
	int d;
};

int main() { 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int ans = 0;
	int r, c, t;
	pos mov[4] = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pos> q1, q2;
	vector<int> cleaner;

	cin >> r >> c >> t;
	vector<vector<int>> a(r, vector<int>(c, 0));
	int d;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> d;
			if (d == -1)
				cleaner.push_back(i);
			else if (d != 0) {
				a[i][j] = d;
				q1.push({ i,j,d });
				ans += d;
			}
		}

	pos front, temp;
	int cnt;
	for (int i = 0; i < t; i++) {
		vector<vector<int>> to_add(r, vector<int>(c, 0));
		while (!q1.empty()) {
			front = q1.front();
			q1.pop();
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				temp = { front.x + mov[j].x, front.y + mov[j].y };
				if ((temp.x == cleaner[0] || temp.x == cleaner[1]) && temp.y == 0)
					continue; //공청기 위치면 확산안함
				else if (temp.x >= 0 && temp.x < r && temp.y >= 0 && temp.y < c) {//확산
					if (a[temp.x][temp.y] == 0 && front.d/5 != 0) {
						a[temp.x][temp.y] = front.d / 5;
						q2.push({ temp.x, temp.y, front.d / 5 });
					}
					else
						to_add[temp.x][temp.y] += front.d / 5;
					cnt++;
				}
			}
			front.d -= (front.d / 5) * cnt;
			q2.push({ front.x, front.y, front.d });	
		}

		vector<vector<int>> new_a(r, vector<int>(c, 0));
		while (!q2.empty()) {
			front = q2.front();
			q2.pop();
			//add dirt
			front.d += to_add[front.x][front.y];
			//cleaned
			if ((front.x + 1 == cleaner[0] || front.x - 1 == cleaner[1]) && front.y == 0){
				ans -= front.d;
				continue;
			}
			//move position
			//right
			if ((front.x == cleaner[0] || front.x == cleaner[1]) && front.y != c - 1)
				front.y++;
			//left
			else if ((front.x == 0 || front.x == r - 1) && front.y != 0)
				front.y--;
			//up
			else if ((front.x > cleaner[1] && front.y == 0) || (front.x <= cleaner[0] && front.x != 0 && front.y == c - 1))
				front.x--;
			//down
			else if ((front.x < cleaner[0] && front.y == 0) || (front.x >= cleaner[1] && front.x != r - 1 && front.y == c - 1))
				front.x++;

			q1.push({ front.x, front.y, front.d });
			new_a[front.x][front.y] = front.d;
		}
		a = new_a;
	}
	cout << ans;
}