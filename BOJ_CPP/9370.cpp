#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 2001;
const int INF = 2000000;
typedef pair<int, int> p;

int T, n, m, t, s, g, h, v1, v2, cur, curd, nxt, nxtd;
vector<p> graph[MAX]; //pair<�������, ����ġ>
vector<int> d(MAX, INF); //�ִܰŸ� ����
priority_queue<p, vector<p>, greater<p>> pq;
int dijkS;

int dijkstra(int start, int end) {
	fill(d.begin(), d.begin()+n+1 , INF); // d �ʱ�ȭ

	d[start] = 0;
	pq.push({ d[start], start });

	while (!pq.empty()) {
		cur = pq.top().second;
		curd = pq.top().first;
		pq.pop();
		if (curd > d[cur])
			continue;

		for (auto p : graph[cur]) {
			nxt = p.first;
			nxtd = p.second + curd;
			if (nxtd < d[nxt]) {
				d[nxt] = nxtd;
				pq.push({ d[nxt], nxt });
			}
		}
	}
	return d[end];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//input
	cin >> T;
	int a, b, d, gh, sg, sh;
	for (int i = 0 ; i < T ; i++) {
		cin >> n >> m >> t; //������(����), ����, �������ĺ� ����
		cin >> s >> g >> h; //�����, ������ �� g-h

		for (int i = 1; i <= n; i++)
			graph[i].clear();

		for (int i = 0 ; i < m ; i++) {
			cin >> a >> b >> d;
			if ((a == g && b == h) || b == g && a == h)
				gh = d;
			graph[a].push_back({ b, d });
			graph[b].push_back({ a, d }); //����⵵��
		}
		vector<int> dest(t); //������ �ĺ��� ���� ����
		for (int i = 0 ; i < t ; i++)
			cin >> dest[i];

		vector<int> ans; // ������ ���� ����
		//find answer
		sg = dijkstra(s, h) + gh;
		sh = dijkstra(s, g) + gh;
		p rightPath;
		if (sg > sh)
			rightPath = { h, sh };
		else
			rightPath = { g, sg };
 
		for (int i = 0 ; i < t ; i++) {
			int comp = rightPath.second + dijkstra(rightPath.first, dest[i]);
			if (comp == dijkstra(s, dest[i]))
				ans.push_back(dest[i]);
		}

		//output
		sort(ans.begin(), ans.end());
		for (int i = 0 ; i < ans.size() ; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
}