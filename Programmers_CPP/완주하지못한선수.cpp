#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> hmap;

	for (string s : completion)
		hmap[s]++;

	for (string s : participant) {
		hmap[s]--;
		if (hmap[s] == -1)
			return s;
	}
}