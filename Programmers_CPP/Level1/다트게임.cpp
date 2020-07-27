#include <string>
#include <math.h>

using namespace std;

int solution(string dartResult) {
	int count = 0;
	int temp[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++) {
		if (dartResult[count + 1] == '0') {
			temp[i] = 10;
			count += 2;
		}
		else {
			temp[i] = dartResult[count] - '0';
			count++;
		}
		//
		if (dartResult[count] == 'S')
			temp[i] = temp[i];
		else if (dartResult[count] == 'D')
			temp[i] = temp[i] * temp[i];
		else if (dartResult[count] == 'T')
			temp[i] = temp[i] * temp[i] * temp[i];
		count++;
		//
		if (count < dartResult.size()) {
			if (dartResult[count] == '*') {
				temp[i] *= 2;
				if (i > 0)
					temp[i - 1] *= 2;
				count++;
			}
			else if (dartResult[count] == '#') {
				temp[i] *= -1;
				count++;
			}
		}
	}

	return temp[0] + temp[1] + temp[2];
}