#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
bool promising, complete = false;
int index[3][3] = { {0,1,2}, {3,4,5}, {6,7,8} };
vector<pair<int, int>> toFill;

void sudoku(int fill_index) {
	if (fill_index == toFill.size())
		complete = true;

	else {
		int x, y;
		for (int i = 1; i <= 9; i++) {
			//int x, y;
			x = toFill[fill_index].first;
			y = toFill[fill_index].second;
			promising = true;
			for (int j = 0; j < 9; j++)
				if (board[x][j] == i || board[j][y] == i) {//가로/세로
					promising = false;
					break;
				}
			if (promising) {
				for (int j : index[x / 3]) //3*3사각형에서 후보 탐색
					for (int k : index[y / 3])
						if (board[j][k] == i) {
							promising = false;
							break;
						}
			}
			if (promising) {
				board[x][y] = i;
				sudoku(fill_index + 1);
				if (complete)
					return;

				board[x][y] = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				toFill.push_back({ i, j });
		}
	//backtracking
	sudoku(0);
	//output
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}