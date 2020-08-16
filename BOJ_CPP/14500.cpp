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
			if (i < n - 3) // 1 ����
				temp[0] = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
			if (j < m - 3)  // 1 ����
				temp[1] = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
			if (i < n - 1 && j < m - 1) // 2
				temp[2] = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
			if (i < n - 2 && j < m - 1)  // 3 �⺻
				temp[3] = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) // 3 �ð���� 90��
				temp[4] = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j];
			if (i < n - 2 && j < m - 1)  //3 180��
				temp[5] = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) // 3 �ð�ݴ� 90��
				temp[6] = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 2];
			if (i < n - 2 && j < m - 1) //3 �¿��Ī
				temp[7] = board[i + 2][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) // 3 �¿��Ī �ð� 90��
				temp[8] = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (i < n - 2 && j < m - 1) // 3 �¿��Ī 180��
				temp[9] = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1];
			if (i < n - 1 && j < m - 2) // 3 �¿��Ī �ð�ݴ� 90��
				temp[10] = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
			if (i < n - 2 && j < m - 1) //4
				temp[11] = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) //4 �ð���� 90��
				temp[12] = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i][j + 2];
			if (i < n - 2 && j < m - 1) // 4 �¿��Ī
				temp[13] = board[i + 1][j] + board[i + 2][j] + board[i][j + 1] + board[i + 1][j + 1];
			if (i < n - 1 && j < m - 2) // 4 �¿��Ī �ð���� 90��
				temp[14] = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (i < n - 1 && j < m - 2) // 5
				temp[15] = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i][j + 2];
			if (i < n - 2 && j < m - 1) // 5 �ð���� 90��
				temp[16] = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (i < n - 1 && j < m - 2) // 5 180��
				temp[17] = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (i < n - 2 && j < m - 1) // 5 �ð�ݴ� 90��
				temp[18] = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];

			ans = max(ans, *max_element(begin(temp), end(temp)));
		}
	cout << ans;
}