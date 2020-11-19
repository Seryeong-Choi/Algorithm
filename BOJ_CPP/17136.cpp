#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> board(10, vector<int>(10, 0));
vector<int> paper = { 0,0,0,0,0,0 };
int ans = 999;
void solution(int x, int y) {
	if (y == 10) {
		x += 1;
		y = 0;
	}

	if (x == 10 && y == 0){
		int temp = 0;
		for (int cnt : paper)
			temp += cnt;
		ans = min(ans, temp);
	}
	else if (board[x][y] == 1) {
		for (int size = 1; size <= 5; size++) {
			if (paper[size] < 5 && x + size <= 10 && y + size <= 10) {
				bool flag = true;
				for (int j = x; j < x + size; j++) {
					for (int k = y; k < y + size; k++) {
						if (board[j][k] == 1)
							continue;
						else {
							flag = false;
							break;
						}
					}
					if (!flag)
						break;
				}
				if (flag) {
					for (int j = x; j < x + size; j++)
						for (int k = y; k < y + size; k++)
							board[j][k] = 2;
					paper[size]++;
					solution(x, y + 1);
					paper[size]--;
					for (int j = x; j < x + size; j++)
						for (int k = y; k < y + size; k++)
							board[j][k] = 1;
				}
			}
		}
	}
	else
		solution(x, y + 1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> board[i][j];

	solution(0, 0);
	
	if (ans == 999)
		cout << -1;
	else
		cout << ans;
}