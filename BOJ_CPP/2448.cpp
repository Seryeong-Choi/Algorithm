#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> lines(3072, vector<char>(6144, ' '));

void star(int x, int y, int size){ // ¸ÇÀ§²ÀÁşÁ¡ ÁÂÇ¥, »ï°¢Çü³ôÀÌ
	if (size == 3) {
		lines[x][y] = '*';
		lines[x + 1][y - 1] = '*';
		lines[x + 1][y + 1] = '*';
		for (int i = y - 2 ; i <= y + 2 ; i++)
			lines[x+2][i] = '*';
	}
	else {
		star(x, y, size / 2);
		star(x + size / 2, y - size / 2, size / 2);
		star(x + size / 2, y + size / 2, size / 2);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n;

	//output
	star(0,n-1,n);

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < 2 * n - 1; j++)
			cout << lines[i][j];
		cout << "\n";
	}
}