#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}


int solution(vector<int> priorities, int location) {
	int answer = 0;
	deque<pair<int, int>> print;
	//int temp;

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

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> location(n, 0);
	vector<int> k(n, 0);
	vector<vector<int>> prior(n);

	for (int i = 0; i < n; i++) {
		cin >> k[i];
		cin >> location[i];
		int temp;
		for (int j = 0; j < k[i]; j++) {
			cin >> temp;
			prior[i].push_back(temp);
		}
	}

	for(int i = 0 ; i < n ; i++)
		cout << solution(prior[i], location[i]) << "\n";
}