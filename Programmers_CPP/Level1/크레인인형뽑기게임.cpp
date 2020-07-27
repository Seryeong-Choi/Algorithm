#include <string>
#include <vector>

using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<vector<int>> nboard(board.size(),vector<int>(board.size(),0));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++){
			if (board[board.size() - j - 1][i] != 0)
				nboard[i][j] = board[board.size() - j - 1][i];
			else
				nboard[i].pop_back();
		}
	}

	vector<int> basket;
	for (int i = 0; i < moves.size(); i++) {
		if (!nboard[moves[i] - 1].empty()) {
			basket.push_back(nboard[moves[i] - 1].back());
			if (basket.size() >= 2)
				if (basket[basket.size() - 1] == basket[basket.size() - 2]) {
					basket.pop_back();
					basket.pop_back();
					answer += 2;
				}
			nboard[moves[i] - 1].pop_back();
		}
	}
	return answer;
}