#include <string>
#include <vector>
#include <iostream>

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

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string arrangement;
	cin >> arrangement;

	cout << solution(arrangement);
}