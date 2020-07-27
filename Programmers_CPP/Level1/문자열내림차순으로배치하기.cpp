#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s);
int main() {

	cout << solution("Zbcdefg");
	return 0;
}

string solution(string s) {
	string answer = "";
	vector<char> v;

	for (int i = 0; i < s.length(); i++)
		v.push_back(s[i]);

	sort(v.begin(), v.end(),greater<char>());

	for (int i = 0; i < v.size(); i++)
		answer += v[i];

	return answer;
}