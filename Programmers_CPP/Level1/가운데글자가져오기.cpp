#include <string>
#include <vector>
#include <iostream>
using namespace std;
string solution(string s);
int main() {
	cout << solution("qwer");
	return 0;
}

string solution(string s) {
	string answer = "";
	if (s.length() % 2 == 0) {
		answer = "  ";
		answer[0] = s[s.length() / 2 - 1];
		answer[1] = s[s.length() / 2];

	}
	else
		answer = s[(s.length() - 1) / 2];
	return answer;
}