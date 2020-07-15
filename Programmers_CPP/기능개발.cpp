#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds);
int main() {
	vector<int> ans = solution({ 93,30,55 }, { 1,30,5 });
	for (int n : ans)
		cout << n;
	return 0;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	deque<int> pro, spe;
	int temp = 0;

	for (int i = 0; i < progresses.size(); i++) {
		pro.push_back(progresses[i]);
		spe.push_back(speeds[i]);
	}

	while (!pro.empty()) {
		for (int i = 0; i < pro.size(); i++) {
			pro[i] += spe[i];
		}
		while (!pro.empty() && pro[0] >= 100) {
			pro.pop_front();
			spe.pop_front();
			temp++;
		}
		if (temp != 0) {
			answer.push_back(temp);
			temp = 0;
		}
	}
	return answer;
}