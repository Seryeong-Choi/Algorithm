#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h, check, ans = 4;
bool ladder[12][31]; //세로줄-가로줄
bool flag;

void solution(int column, int row, int count) {
	for (int i = 0; i < n; i++) {
		flag = true;
		check = i;
		for (int j = 0; j < h; j++) {
			if (ladder[check][j])
				check++;
			else if (check > 0 && ladder[check - 1][j])
				check--;
		}
		if (check == i)
			continue;
		else {
			flag = false;
			break;
		}
	}

	if (flag) {
		ans = min(ans, count);
	}
	else if (count + 1 < ans) {
		for (int j = column; j < n - 1; j++) {
			if (ladder[j][row])
				j++;
			else if (ladder[j + 1][row])
				j = j + 2;
			else {
				ladder[j][row] = true;
				if (j == n - 2)
					solution(0, row + 1, count + 1);
				else
					solution(j + 1, row, count + 1);
				ladder[j][row] = false;
			}
		}
		for (int i = row + 1; i < h; i++)
			for (int j = 0; j < n - 1; j++) {
				if (ladder[j][i])
					j++;
				else if (ladder[j + 1][i])
					j = j + 2;
				else {
					ladder[j][i] = true;
					if (j == n - 2)
						solution(0, i + 1, count + 1);
					else
						solution(j + 1, i, count + 1);
					ladder[j][i] = false;
				}
			}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m >> h;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ladder[b - 1][a - 1] = true;
	}

	solution(0, 0, 0);
	if (ans == 4)
		cout << -1;
	else
		cout << ans;
}