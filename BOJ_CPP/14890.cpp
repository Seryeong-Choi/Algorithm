#include <iostream>
using namespace std;

typedef pair<int, int> pos;
int n, l, ans = 0, map[100][100], sl[100][100] = { 0 }, base;
bool flag;

void slope() {
	for (int i = 0; i < n; i++) {
		base = map[i][0];
		flag = true;
		for (int j = 1; j < n; j++) {//����
			if (map[i][j] == base)
				continue; //����ĭ �̵�
			else if (map[i][j] - base < -1 || map[i][j] - base > 1) {
				flag = false; //�ش��� Ž������
				break;
			}

			else if (map[i][j] - base == -1) { //��������
				if (flag && sl[i][j] == 0) {//���� ���� ������ Ž��
					for (int k = 1; k < l; k++)
						if (j + k >= n || map[i][j] != map[i][j + k] || sl[i][j + k] == 1) {
							flag = false; // ���� ���� �� �ִ��� �Ǵ�
							break;
						}
				}
				if (flag) {
					for (int k = 0; k < l; k++)
						sl[i][j + k] = 1;
					base = map[i][j];
					j += l - 1;
				}
			}
			else if(map[i][j] - base == 1) {//��������
				if (sl[i][j - 1] == 1)
					flag = false;
				if (flag) {//���� ���� ������ Ž��
					for (int k = 2 ; k <= l; k++)
 						if (j - k < 0 || map[i][j - 1] != map[i][j - k] || sl[i][j - k] == 1) {
							flag = false; // ���� ���� �� �ִ��� �Ǵ�
							break;
						}
				}
				if (flag) {
					for (int k = 1; k <= l; k++)
						sl[i][j - k] = 1;
					base = map[i][j];
				}
			}
		}
		if (flag) //������ �� �ִ� ���̸�
			ans++;
	}

	for (int i = 0; i < n; i++)
		fill(begin(sl[i]), end(sl[i]), 0);

	for (int i = 0; i < n; i++) {
		base = map[0][i];
		flag = true;
		for (int j = 1; j < n; j++) {//����
			if (map[j][i] == base)
				continue; //����ĭ �̵�
			else if (map[j][i] - base < -1 || map[j][i] - base > 1) {
				flag = false; //�ش��� Ž������
				break;
			}

			else if (map[j][i] - base == -1) { //��������
				if (flag && sl[j][i] == 0) {//���� ���� ������ Ž��
					for (int k = 1; k < l; k++)
						if (j + k >= n || map[j][i] != map[j + k][i] || sl[j + k][i] == 1) {
							flag = false; // ���� ���� �� �ִ��� �Ǵ�
							break;
						}
				}
				if (flag) {
					for (int k = 0; k < l; k++)
						sl[j + k][i] = 1;
					base = map[j][i];
					j += l - 1;
				}
			}
			else if (map[j][i] - base == 1) {//��������
				if (sl[j - 1][i] == 1) //���� ���� ������ Ž��
					flag = false;
				if (flag) {
					for (int k = 2; k <= l; k++)
						if (j - k < 0 || map[j - 1][i] != map[j - k][i] || sl[j - k][i] == 1) {
							flag = false; // ���� ���� �� �ִ��� �Ǵ�
							break;
						}
				}
				if (flag) {
					for (int k = 1; k <= l; k++)
						sl[j - k][i] = 1;
					base = map[j][i];
				}
			}
		}
		if (flag) //������ �� �ִ� ���̸�
			ans++;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> l;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	//
	slope();
	//output
	cout << ans;
}
