#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	auto it = min_element(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
		if (arr[i] != *it)
			answer.push_back(arr[i]);

	if (answer.size() == 0)
		answer.push_back(-1);

	return answer;
}