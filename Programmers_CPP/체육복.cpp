#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	vector<int> students(n, 0);

	for (int i : reserve) {
		if (find(lost.begin(), lost.end(), i) == lost.end())
			students[i - 1] = 1;
		else
			students[i - 1] = 2; //여벌 있지만 도난당한경우
	}

	for (int i : lost) {
		if (students[i - 1] == 2) {
			students[i - 1] = 0;
			answer++;//자기자신에게 빌린 것이라고 생각
		}
		else if (i == 1 && students[i] == 1) {
			students[i] = 0;
			answer++;
		}
		else if (i == n && students[i - 2] == 1) {
			students[i - 2] = 0;
			answer++;
		}
		else if (students[i - 2] == 1) {
			students[i - 2] = 0;
			answer++;
		}
		else if (students[i] == 1) {
			students[i] = 0;
			answer++;
		}
	}

	return answer;
}