#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20001;
typedef pair<int, int> p;

int v, e, k, cur, curd, nxt, nextd;
vector<p> graph[MAX]; //pair<�������, ����ġ> //������ �����ϴ� �׷���
vector<int> d(MAX, 200000); //�ִܰŸ� ����
priority_queue<p, vector<p>, greater<p>> pq;

void dijkstra() {
	d[k] = 0;
	pq.push({ d[k], k});

	while (!pq.empty()) {
		cur = pq.top().second; // ť���� �� ����
		curd = pq.top().first;
		pq.pop();

		if (d[cur] < curd) //ť�� ���� �̹� ����� �ִܰŸ����� ũ�� �ǳʶ�
			continue;

		for (auto p : graph[cur]) { // ���� cur�� ����� ���� Ȯ��
			nxt = p.first;
			nextd = p.second + curd; // cur - nxt ������ weight + cur������ �ִܰŸ�

			if (nextd < d[nxt]) { // �ִܰŸ� ������ �Ͼ��� push 
				d[nxt] = nextd; // ���� nxt�� ó�� �湮�Ұ�� ������ push�� (visited ���ʿ�)
				pq.push({ d[nxt], nxt });
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> v >> e >> k; // ���� >> �������� >> ��������
	int a, b, c;
	for (int i = 0 ; i < e ; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	
	dijkstra();
	//output
	for (int i = 1; i <= v; i++) {
		if (d[i] == 200000)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}
}