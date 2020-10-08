import sys
from collections import deque

n = int(sys.stdin.readline())
drawing = []
for i in range(n):
    drawing.append(sys.stdin.readline())

rg = 0
default = 0
visited = [[0 for i in range(n)] for j in range(n)]
mov = [[1, 0], [0, 1], [-1, 0], [0, -1]]
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            q = deque()
            q.append([i, j])
            visited[i][j] = 1
            while q:
                now = q.popleft()
                for k in range(4):
                    nxt = [now[0] + mov[k][0], now[1] + mov[k][1]]
                    if nxt[0] >= 0 and nxt[0] < n and nxt[1] >= 0 and nxt[1] < n and visited[nxt[0]][nxt[1]] == 0:
                        if drawing[now[0]][now[1]] == drawing[nxt[0]][nxt[1]]:
                            q.append(nxt)
                            visited[nxt[0]][nxt[1]] = 1
            default += 1

visited = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            q = deque()
            q.append([i, j])
            visited.append([i, j])
            while q:
                now = q.popleft()
                for k in range(4):
                    nxt = [now[0] + mov[k][0], now[1] + mov[k][1]]
                    if nxt[0] >= 0 and nxt[0] < n and nxt[1] >= 0 and nxt[1] < n and visited[nxt[0]][nxt[1]] == 0:
                        if (drawing[now[0]][now[1]] != 'B' and drawing[nxt[0]][nxt[1]] != 'B') or drawing[now[0]][
                            now[1]] == drawing[nxt[0]][nxt[1]]:
                            q.append(nxt)
                            visited[nxt[0]][nxt[1]] = 1
            rg += 1

print(default, rg)
