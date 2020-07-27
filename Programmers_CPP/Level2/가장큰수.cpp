#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
	string as = to_string(a);
	string bs = to_string(b);
	string temp = as;
	as += bs;
	bs += temp;
	return stoi(as) > stoi(bs);
}

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), comp);

	for (int i : numbers)
		answer += to_string(i);

	if (answer[0] == '0')
		return to_string(0);
	else
		return answer;
}