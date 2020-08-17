#include <iostream>
using namespace std;

typedef pair<int, int> pos;
int n, m, r, c, tr, tc, d, td, ans = 0, room[50][50]; //0:��ĭ 1:�� 2:û����
pos turn[4] = { {-1,0}, {0,1}, {1,0}, {0, -1} };

//dfs
void cleaning() {
	if (room[r][c] == 0) {
		room[r][c] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++) {
		td = (d + 3 - i) % 4;
		tr = r + turn[td].first;
		tc = c + turn[td].second;
		if (tr >= 0 && tr < n && tc >= 0 && tc < m)
			if (room[tr][tc] == 0) {
				r = tr;
				c = tc;
				d = td;
				cleaning();
			}
	}

	tr = r + turn[(td + 2) % 4].first;//������ǥ
	tc = c + turn[(td + 2) % 4].second;
	if (room[tr][tc] == 1) //�ڰ� ���̸� ����
		return;
	else { //���������ϸ� ���� //������ ĭ�� û�� �Ǿ������Ƿ� 1�� ���� ����
		d = td;
		r = tr;
		c = tc;
		cleaning();
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> room[i][j];

	cleaning();
	cout << ans;
}
