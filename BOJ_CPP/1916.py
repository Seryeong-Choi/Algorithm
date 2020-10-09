import sys
import heapq

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

graph = [[] for i in range(n + 1)]
for i in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append([b, c])
start, end = map(int, sys.stdin.readline().split())

dist = [222222222 for i in range(n + 1)]
pq = []
dist[start] = 0
heapq.heappush(pq, [dist[start], start])

while pq:
    cur = heapq.heappop(pq) #shortestdist, node
    for nxt in graph[cur[1]]: #node, graphdist
        if dist[nxt[0]] > cur[0] + nxt[1]:
            dist[nxt[0]] = cur[0] + nxt[1]
            heapq.heappush(pq, [dist[nxt[0]], nxt[0]])

print(dist[end])
