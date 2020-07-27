#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	int days = b;
	for (int i = 1; i < a; i++) {
		if (i == 2)
			days += 29;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			days += 30;
		else
			days += 31;
	}
	vector<string> day = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
	return day[days % 7];
}