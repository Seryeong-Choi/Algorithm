#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	int size = citations.size();

	for (int i = 0; i < size / 2 + 1; i++) {
		if (citations[i] < size && citations[i] <= size - i && citations[i] > answer) {
			answer = citations[i];
		}
		else if (citations[i] >= size - i && size - i > answer) {
			answer = size - i;
		}
	}

	return answer;
}