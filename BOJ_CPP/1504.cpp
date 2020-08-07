#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 801;
const int INF = 800000;
typedef pair<int, int> p;

int n, e, v1, v2, cur, curd, nxt, nxtd;
vector<p> graph[MAX]; //pair<도착노드, 가중치>
vector<int> d(MAX, INF); //최단거리 저장
priority_queue<p, vector<p>, greater<p>> pq;

int dijkstra(int start, int end) {
	d[start] = 0;
	pq.push({d[start], start});

	while (!pq.empty()) {
		cur = pq.top().second;
		curd = pq.top().first;
		pq.pop();
		if (d[cur] < curd)
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
	cin >> n >> e; //정점 >> 간선개수
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c }); //방향 없는 그래프
	}
	cin >> v1 >> v2; //반드시 지날 정점
	int onetov1 = dijkstra(1, v1);
	fill(d.begin(), d.end(), INF);
	int onetov2 = dijkstra(1, v2);
	fill(d.begin(), d.end(), INF);
	int v1tov2 = dijkstra(v1, v2);
	fill(d.begin(), d.end(), INF);
	int v1ton = dijkstra(v1, n);
	fill(d.begin(), d.end(), INF);
	int v2ton = dijkstra(v2, n);
	//output
	int ans = min(onetov1 + v1tov2 + v2ton, onetov2 + v1tov2 + v1ton);
	if (ans >= INF) cout << -1;
	else cout << ans;
}