#include <string>
#include <vector>
#include <iostream>

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

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	vector<int> heights;
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		heights.push_back(temp);
	}

	vector<int> ans = solution(heights);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}