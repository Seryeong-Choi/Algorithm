#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	iota(answer.begin(), answer.end(), 0);
	reverse(answer.begin(), answer.end());

	vector<pair<int, int>> stack;

	for (int i = 0; i < prices.size(); i++) {
		while (!stack.empty() && stack.back().first > prices[i]) {
			answer[stack.back().second] = i - stack.back().second;
			stack.pop_back();
		}
		stack.push_back(pair<int, int>(prices[i], i));
	}

	return answer;
}