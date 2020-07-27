#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size(), 0);
	vector<pair<int, int>> stack;

	for (int i = heights.size() - 1; i >= 0; i--) {
		while (!stack.empty() && heights[i] > stack.back().first) {
			answer[stack.back().second] = i + 1;
			stack.pop_back();
		}
		stack.push_back(pair<int, int>(heights[i], i));
	}

	return answer;
}