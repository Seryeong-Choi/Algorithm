#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<float, int> a, pair<float, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<float> a(N + 2, 0);
	for (int i : stages)
		a[i]++;

	vector<pair<float, int>> b;
	for (int i = 0; i < N + 2; i++)
		b.push_back(pair<float, int>(a[i], i));

	for (int i = N; i > 0; i--) {
		b[i].first += b[i + 1].first;
		if (a[i + 1] == 0)
			b[i + 1].first = 0;
		else
			b[i + 1].first = a[i + 1] / b[i + 1].first;
	}
	b[1].first = a[1] / b[1].first;

	sort(b.begin(), b.end(), compare);

	for (int i = 0; i < N + 2; i++)
		if (b[i].second != 0 && b[i].second != N + 1)
			answer.push_back(b[i].second);

	return answer;
}