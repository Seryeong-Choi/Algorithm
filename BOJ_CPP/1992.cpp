#include <iostream>
#include <string>
using namespace std;

int n, video[64][64];
bool stop = true;

void quadtree(int x, int y, int n) {
	stop = true;
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (video[i][j] != video[x][y])
				stop = false;

	if (stop) {
		cout << video[x][y];
	}
		
	else {
		cout << '(';
		quadtree(x, y, n / 2);
		quadtree(x, y + n / 2, n / 2);
		quadtree(x + n / 2, y, n / 2);
		quadtree(x + n / 2, y + n / 2, n / 2);
		cout << ')';
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++)
			video[i][j] = s[j] - '0';
	}
	//divide and conquer
	quadtree(0, 0, n);
}