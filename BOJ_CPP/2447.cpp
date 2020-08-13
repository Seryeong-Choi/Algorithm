#include <iostream>
using namespace std;

int n;
char lines[6561][6561];

void star(int x, int y, int size){
	if (size == 3) {
		for (int i = x; i < x + 3; i++)
			for (int j = y; j < y + 3; j++)
				lines[i][j] = '*';
		lines[x + 1][y + 1] = ' ';
	}

	else {
		for (int i = x + size / 3 ; i < x + size * 2 / 3 ; i++)
			for (int j = y + size / 3 ; j < y + size * 2 / 3 ; j++)
				lines[i][j] = ' ';

		star(x, y, size / 3);
		star(x, y + size / 3, size / 3);
		star(x, y + size * 2 / 3, size / 3);
		star(x + size / 3, y, size / 3);
		star(x + size / 3, y + size * 2 / 3, size / 3);
		star(x + size * 2 / 3, y, size / 3);
		star(x + size * 2 / 3, y + size / 3, size / 3);
		star(x + size * 2 / 3, y + 2 * size / 3, size / 3);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n;

	//output
	star(0,0,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << lines[i][j];
		cout << "\n";
	}
}