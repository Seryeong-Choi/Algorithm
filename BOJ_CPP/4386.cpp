#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct pos {
	double x;
	double y;
};

struct edge {
	double dist;
	int v1;
	int v2;
};

vector<int> parent, t_rank;

int find(int vertex) {
	if (parent[vertex] == vertex)
		return vertex;

	return parent[vertex] = find(parent[vertex]);
}

void merge(int v1, int v2) {
	if (t_rank[v1] < t_rank[v2]) {
		parent[v1] = v2;
	}
	else {
		parent[v2] = v1;
		if (t_rank[v1] == t_rank[v2])
			t_rank[v1] ++;
	}
}

bool compare(edge e1, edge e2) {
	if (e1.dist < e2.dist) return true;
	else return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	double x, y;
	cin >> n;
	vector<pos> stars;
	t_rank.assign(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		stars.push_back({ x,y });
		parent.push_back(i);
	}
	vector<edge> edges;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt((stars[i].x - stars[j].x) * (stars[i].x - stars[j].x) +
				(stars[i].y - stars[j].y) * (stars[i].y - stars[j].y));
			edges.push_back({ dist, i, j });
		}
	}
	sort(edges.begin(), edges.end(), compare);

	double ans = 0;
	for (edge e : edges) {
		int parent_v1 = find(e.v1);
		int parent_v2 = find(e.v2);
		if (parent_v1 != parent_v2) {
			ans += e.dist;
			merge(parent_v1, parent_v2);
		}
	}
	printf("%.2f\n", ans);
}