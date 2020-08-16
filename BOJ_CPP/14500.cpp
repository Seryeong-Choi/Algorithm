#include <iostream>
#include <algorithm>
using namespace std;

int n, m, board[500][500], ans = 0, temp[19];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for(int i = 0 ; i < n ; i++)
		for (int j = 0; j < m; j++) {
			if (i < n - 3) // 1 세로
				temp[0] = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
			if (j < m - 3)  // 1 가로
				temp[1] = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
			if (i < n - 1 && j < m - 1) // 2
				temp[2] = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
			if (i < n - 2 && j < m - 1)  // 3 기본
				temp[3] = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) // 3 시계방향 90도
				temp[4] = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j];
			if (i < n - 2 && j < m - 1)  //3 180도
				temp[5] = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) // 3 시계반대 90도
				temp[6] = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 2];
			if (i < n - 2 && j < m - 1) //3 좌우대칭
				temp[7] = board[i + 2][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) // 3 좌우대칭 시계 90도
				temp[8] = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (i < n - 2 && j < m - 1) // 3 좌우대칭 180도
				temp[9] = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1];
			if (i < n - 1 && j < m - 2) // 3 좌우대칭 시계반대 90도
				temp[10] = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
			if (i < n - 2 && j < m - 1) //4
				temp[11] = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) //4 시계방향 90도
				temp[12] = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i][j + 2];
			if (i < n - 2 && j < m - 1) // 4 좌우대칭
				temp[13] = board[i + 1][j] + board[i + 2][j] + board[i][j + 1] + board[i + 1][j + 1];
			if (i < n - 1 && j < m - 2) // 4 좌우대칭 시계방향 90도
				temp[14] = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (i < n - 1 && j < m - 2) // 5
				temp[15] = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i][j + 2];
			if (i < n - 2 && j < m - 1) // 5 시계방향 90도
				temp[16] = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) // 5 180도
				temp[17] = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (i < n - 2 && j < m - 1) // 5 시계반대 90도
				temp[18] = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];

			ans = max(ans, *max_element(begin(temp), end(temp)));
		}
	cout << ans;
}