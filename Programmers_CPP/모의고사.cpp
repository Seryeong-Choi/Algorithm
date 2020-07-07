#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> answers);

int main() {
	vector<int> answers = solution({ 1,2,3,4,5 });
	
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;

	return 0;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> score = { 0,0,0 };
	vector<int> first = { 1,2,3,4,5 };
	vector<int> second = { 2,1,2,3,2,4,2,5 };
	vector<int> third = { 3,3,1,1,2,2,4,4,5,5 };

	for (int i = 0; i < answers.size(); i++)
		if (answers[i] == first[i % 5])
			score[0]++;

	for (int i = 0; i < answers.size(); i++)
		if (answers[i] == second[i % 8])
			score[1]++;

	for (int i = 0; i < answers.size(); i++)
		if (answers[i] == third[i % 10])
			score[2]++;
	
	for (int i = 0; i < 3; i++)
		if (score[i] == *max_element(score.begin(), score.end()))
			answer.push_back(i+1);

	return answer;
}