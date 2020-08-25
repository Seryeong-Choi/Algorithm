#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
	int len = s.length(), ans = len, temp, cnt;

	for (int i = 1; i <= len / 2; i++) { //���ڿ� ����
		string base = s.substr(0, i); //Ž�����ع��ڿ�
		temp = len; //���ڿ� ����
		int j = 0;
		cnt = 1;

		while (j <= len - i) {
			if (base == s.substr(j + i, i)) {
				temp -= i;
				cnt++;
			}
			else {
				if (cnt > 1) {
					temp += to_string(cnt).length();//����÷�� ���
					cnt = 1;
				}
				base = s.substr(j + i, i);
			}
			j += i;
		}
		ans = min(ans, temp);
	}
	return ans;
}