#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z' - n)
			s[i] += n;
		else if (s[i] > 'z' - n && s[i] <= 'z')
			s[i] = s[i] + n - 26;
		else if (s[i] >= 'A' && s[i] <= 'Z' - n)
			s[i] += n;
		else if (s[i] > 'Z' - n && s[i] <= 'Z')
			s[i] = s[i] + n - 26;
	}

	answer = s;
	return answer;
}