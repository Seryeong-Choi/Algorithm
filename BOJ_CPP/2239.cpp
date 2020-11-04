#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct pos {
	int r;
	int c;
};
vector<pos> to_fill;
vector<string> sudoku;
bool end_flag = false;
vector<vector<int>> three_by_three = { {0,1,2},{3,4,5},{6,7,8} };

void solution(int index) {
	if (index == to_fill.size())
		end_flag = true;
	else {
		int r = to_fill[index].r;
		int c = to_fill[index].c;
		for (int i = 1; i <= 9; i++) {
			bool flag = true;
			for (int j = 0; j < 9; j++) {
				if (sudoku[r][j] == char(i + '0') || sudoku[j][c] == char(i + '0')) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j : three_by_three[r / 3]) {
					for (int k : three_by_three[c / 3]) {
						if (sudoku[j][k] == char(i + '0')) {
							flag = false;
							break;
						}
					}
					if (!flag)
						break;
				}
			}
			if (flag) {
				sudoku[r][c] = char(i + '0');
				solution(index + 1);
				if (end_flag)
					return;
				else
					sudoku[r][c] = '0';
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	for (int i = 0; i < 9; i++) {
		cin >> str;
		sudoku.push_back(str);
		for (int j = 0; j < 9; j++)
			if (str[j] == '0')
				to_fill.push_back({ i, j });
	}

	solution(0);

	for (string str : sudoku)
		cout << str << '\n';
}