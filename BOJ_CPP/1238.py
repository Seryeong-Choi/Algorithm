import sys
import heapq

n, m, x = map(int, sys.stdin.readline().split())
graphA = [[] for i in range(n + 1)]
graphB = [[] for i in range(n + 1)]
distA = [987654321 for i in range(n + 1)]
distB = [987654321 for i in range(n + 1)]
for i in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graphA[a].append([c, b])
    graphB[b].append([c, a])

pq = []
distA[x] = 0
heapq.heappush(pq, [0, x])
while (pq):
    now = heapq.heappop(pq)
    for nxt in graphA[now[1]]:
        if nxt[0] + now[0] < distA[nxt[1]]:
            distA[nxt[1]] = nxt[0] + now[0]
            heapq.heappush(pq, [distA[nxt[1]], nxt[1]])

distB[x] = 0
heapq.heappush(pq, [0, x])
while (pq):
    now = heapq.heappop(pq)
    for nxt in graphB[now[1]]:
        if nxt[0] + now[0] < distB[nxt[1]]:
            distB[nxt[1]] = nxt[0] + now[0]
            heapq.heappush(pq, [distB[nxt[1]], nxt[1]])

ans_index = -1
ans_val = -1
for i in range(1, n + 1):
    distA[i] += distB[i]
    if ans_val < distA[i]:
        ans_index = i
        ans_val = distA[i]
print(ans_val)
