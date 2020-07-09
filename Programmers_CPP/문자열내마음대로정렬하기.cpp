#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	vector<pair<char, string>> temp;

	for (int i = 0; i < strings.size(); i++)
		temp.push_back(pair<char, string>(strings[i][n], strings[i]));

	sort(temp.begin(), temp.end());

	for (int i = 0; i < temp.size(); i++)
		answer.push_back(temp[i].second);

	return answer;
}