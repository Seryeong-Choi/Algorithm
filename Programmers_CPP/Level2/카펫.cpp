#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int max = brown / 2 + 2;
	int x = max - 3, y = 3;

	while ((x - 2) * (y - 2) != yellow) {
		x--;
		y++;
	}
	answer.push_back(x);
	answer.push_back(y);
	return answer;
}