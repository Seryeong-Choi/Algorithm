#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, string> id;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, string>> log; //action, id
	int index;
	string temp, nick, new_nick;
	for (string s : record) {
		if (s[0] == 'C') {
			temp = "";
			new_nick = "";
			index = 7;
			while (s[index] != ' ')
				temp += s[index++];
			index++;
			while (index < s.length())
				new_nick += s[index++];

			id[temp] = new_nick;
		}
		else if (s[0] == 'E') {
			index = 6;
			temp = "";
			nick = "";
			while (s[index] != ' ')
				temp += s[index++];
			index++;
			while (index < s.length())
				nick += s[index++];

			if (id.find(temp) == id.end())
				id.insert({ temp, nick });
			else if (id[temp] != nick)
				id[temp] = nick;

			log.push_back({ s.substr(0, 5), temp });
		}
		else {
			index = 6;
			temp = "";
			while (index < s.length())
				temp += s[index++];
			log.push_back({ s.substr(0, 5), temp });
		}
	}

	for (pair<string, string> p : log) {
		temp = id[p.second];
		if (p.first == "Enter")
			temp += "님이 들어왔습니다.";
		else
			temp += "님이 나갔습니다.";

		answer.push_back(temp);
	}

	return answer;
}