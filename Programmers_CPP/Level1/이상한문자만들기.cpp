#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int index = 0;
	for (char c : s) {
		if (c == ' ') {
			index = 0;
			answer += c;
		}
		else if (index % 2 == 1 && c >= 'A' && c <= 'Z') {
			answer += c + 32;
			index++;
		}
		else if (index % 2 == 0 && c >= 'a' && c <= 'z') {
			answer += c - 32;
			index++;
		}
		else {
			answer += c;
			index++;
		}

	}
	return answer;
}