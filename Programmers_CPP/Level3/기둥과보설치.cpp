#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<bool>> pillar(n + 1, vector<bool>(n + 1, false)); //기둥 x는 0~n y는 0~n-1
	vector<vector<bool>> crossbar(n + 1, vector<bool>(n + 1, false)); //보 : x는 0~n-1 y는 1~n
	int x, y;
	for (int i = 0; i < build_frame.size(); i++) {
		x = build_frame[i][0];
		y = build_frame[i][1];
		if (build_frame[i][3] == 1) { //설치
			if (build_frame[i][2] == 0) {//기둥
				if (y == 0)
					pillar[x][y] = true;
				else if (x - 1 >= 0 && crossbar[x - 1][y])
					pillar[x][y] = true;
				else if (crossbar[x][y])
					pillar[x][y] = true;
				else if (y - 1 >= 0 && pillar[x][y - 1])
					pillar[x][y] = true;
			}
			else { //보
				if (y > 0) {
					if (pillar[x][y - 1])
						crossbar[x][y] = true;
					else if (x < n && pillar[x + 1][y - 1])
						crossbar[x][y] = true;
					else if (x > 0 && crossbar[x - 1][y] && crossbar[x + 1][y])
						crossbar[x][y] = true;
				}
			}
		}
		else {//삭제
			if (build_frame[i][2] == 0)//기둥
				pillar[x][y] = false;
			else if (build_frame[i][2] == 1)//보
				crossbar[x][y] = false;

			bool flag = true;
			for (int k = x - 1; k <= x + 1; k++) {
				for (int j = y - 1; j <= y + 1; j++) {
					if (k >= 0 && k < n + 1 && j >= 0 && j < n + 1) {
						if (pillar[k][j]) {
							if (!(j == 0 || (k - 1 >= 0 && crossbar[k - 1][j]) || crossbar[k][j] || (j - 1 >= 0 && pillar[k][j - 1])))
								flag = false;
						}
						if (crossbar[k][j]) {
							if (!(pillar[k][j - 1] || (k < n && pillar[k + 1][j - 1]) || (k > 0 && crossbar[k - 1][j] && crossbar[k + 1][j])))
								flag = false;
						}
					}
				}
			}
			if (!flag && build_frame[i][2] == 0)
				pillar[x][y] = true;
			else if (!flag && build_frame[i][2] == 1)
				crossbar[x][y] = true;
		}
	}

	vector<vector<int>> answer;
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++) {
			if (pillar[i][j])
				answer.push_back({ i,j,0 });
			if (crossbar[i][j])
				answer.push_back({ i,j,1 });
		}
	return answer;
}