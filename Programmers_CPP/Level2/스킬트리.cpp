#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	string temp;
	for (string s : skill_trees) {
		for (int i = 0; i < s.length(); i++)
			if (skill.find(s[i]) != string::npos)
				temp += s[i];

		if (temp.length() == 0 || skill.substr(0, temp.length()) == temp)
			answer++;
		temp.resize(0);
	}
	return answer;
}