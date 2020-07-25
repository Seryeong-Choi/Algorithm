#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		string temp = "";
		for (int j = 0; j < n; j++) {
			if (arr1[i] % 2 == 0 && arr2[i] % 2 == 0)
				temp = ' ' + temp;
			else
				temp = '#' + temp;
			arr1[i] /= 2;
			arr2[i] /= 2;
		}
		answer.push_back(temp);
	}

	return answer;
}