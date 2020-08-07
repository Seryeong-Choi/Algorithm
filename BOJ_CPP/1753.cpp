#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20001;
typedef pair<int, int> p;

int v, e, k, cur, curd, nxt, nextd;
vector<p> graph[MAX]; //pair<도착노드, 가중치> //방향이 존재하는 그래프
vector<int> d(MAX, 200000); //최단거리 저장
priority_queue<p, vector<p>, greater<p>> pq;

void dijkstra() {
	d[k] = 0;
	pq.push({ d[k], k});

	while (!pq.empty()) {
		cur = pq.top().second; // 큐에서 값 꺼냄
		curd = pq.top().first;
		pq.pop();

		if (d[cur] < curd) //큐의 값이 이미 저장된 최단거리보다 크면 건너뜀
			continue;

		for (auto p : graph[cur]) { // 정점 cur과 연결된 정점 확인
			nxt = p.first;
			nextd = p.second + curd; // cur - nxt 간선의 weight + cur까지의 최단거리

			if (nextd < d[nxt]) { // 최단거리 갱신이 일어날경우 push 
				d[nxt] = nextd; // 정점 nxt에 처음 방문할경우 무조건 push됨 (visited 불필요)
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
	cin >> v >> e >> k; // 정점 >> 간선갯수 >> 시작정점
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