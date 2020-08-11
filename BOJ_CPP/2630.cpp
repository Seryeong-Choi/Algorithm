#include <iostream>
using namespace std;

int n, paper[128][128];
int ans[2] = { 0,0 };
bool stop = true;

void quadtree(int x, int y, int n) {
	stop = true;
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (paper[i][j] != paper[x][y])
				stop = false;

	if (stop)
		ans[paper[x][y]]++;
	else {
		quadtree(x, y, n / 2);
		quadtree(x + n / 2, y, n / 2);
		quadtree(x, y + n / 2, n / 2);
		quadtree(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	//divide and conquer
	quadtree(0, 0, n);
	cout << ans[0] << "\n" << ans[1];
}