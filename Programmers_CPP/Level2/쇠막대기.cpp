#include <string>
#include <vector>

using namespace std;


int solution(string arrangement) {
	int answer = 0;
	string pipes;
	int numOfPipes = 0;
	int Lasers = 0;

	for (int i = 0; i < arrangement.length() - 1; i++) {
		if (arrangement[i] == '(') {
			if (arrangement[i] == '(' && arrangement[i + 1] == ')') {
				answer += numOfPipes;
				i++;
				Lasers++;
			}
			else
				numOfPipes++;
		}
		else
			numOfPipes--;
	}

	answer += (arrangement.length() - Lasers * 2) / 2;

	return answer;
}