#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}


int solution(vector<int> priorities, int location) {
	int answer = 0;
	deque<pair<int, int>> print;
	int temp;

	for (int i = 0; i < priorities.size(); i++)
		print.push_back(pair<int, int>(priorities[i], i));

	pair<int, int> ptemp = *max_element(print.begin(), print.end(), compare);
	int max = ptemp.first;
	int counter = 0;

	while (!print.empty()) {
		if (print[0].first == max) {
			if (print[0].second == location)
				return ++counter;

			print.pop_front();
			counter++;
			if (!print.empty()) {
				pair<int, int> ptemp = *max_element(print.begin(), print.end(), compare);
				max = ptemp.first;
			}
		}
		else {
			ptemp = print.front();
			print.pop_front();
			print.push_back(ptemp);
		}
	}
}