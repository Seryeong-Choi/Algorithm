#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	int a = 0;
	for (int i = 0; i < seoul.size(); i++) {
		a = seoul[i].find("Kim");
		if (a > -1) {
			a = i;
			break;
		}
	}
	answer += "�輭���� ";
	answer += to_string(a);
	answer += "�� �ִ�";

	return answer;
}