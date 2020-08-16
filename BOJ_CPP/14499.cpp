#include <iostream>
using namespace std;

struct dice {
	int top, bottom, left, right, front, back;
};
int n, m, x, y, k, temp;
int map[20][20], roll[1000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> map[i][j];
	for (int i = 0; i < k; i++)
		cin >> roll[i];

	dice d = { 0,0,0,0,0,0 };

	for (int i = 0; i < k; i++) {
		temp = d.bottom;
		if (roll[i] == 1 && y + 1 < m) {//µ¿
			y++;
			d.bottom = d.right;
			d.right = d.top;
			d.top = d.left;
			d.left = temp;
			if (map[x][y] == 0)
				map[x][y] = d.bottom;
			else {
				d.bottom = map[x][y];
				map[x][y] = 0;
			}
			cout << d.top << "\n";
		}
		else if (roll[i] == 2 && y - 1 >= 0) {//¼­
			y--;
			d.bottom = d.left;
			d.left = d.top;
			d.top = d.right;
			d.right = temp;
			if (map[x][y] == 0)
				map[x][y] = d.bottom;
			else {
				d.bottom = map[x][y];
				map[x][y] = 0;
			}
			cout << d.top << '\n';
		}
		else if (roll[i] == 3 && x - 1 >= 0) {//ºÏ
			x--;
			d.bottom = d.back;
			d.back = d.top;
			d.top = d.front;
			d.front = temp;
			if (map[x][y] == 0)
				map[x][y] = d.bottom;
			else {
				d.bottom = map[x][y];
				map[x][y] = 0;
			}
			cout << d.top << "\n";
		}
		else if(roll[i] == 4 && x + 1 < n){//³²
			x++;
			d.bottom = d.front;
			d.front = d.top;
			d.top = d.back;
			d.back = temp;
			if (map[x][y] == 0)
				map[x][y] = d.bottom;
			else {
				d.bottom = map[x][y];
				map[x][y] = 0;
			}
			cout << d.top << "\n";
		}
	}
}