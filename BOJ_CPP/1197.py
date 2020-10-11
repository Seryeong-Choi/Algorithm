import sys

def find(u):
    if u == parent[u]:
        return u
    else:
        parent[u] = find(parent[u])
        return parent[u]

def merge(a,b):
    a_parent = find(a)
    b_parent = find(b)
    if a_parent == b_parent:
        return False
    elif rank[a_parent] >= rank[b_parent]:
        parent[b_parent] = a_parent
        if rank[a_parent] == rank[b_parent]:
            rank[a_parent] += 1
    else:
        parent[a_parent] = b_parent
    return True

v, e = map(int, sys.stdin.readline().split())
parent = [i for i in range(v + 1)]
rank = [1 for i in range(v + 1)]
edges = []
for i in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append([c,a,b])

edges.sort()
ans = 0
for vec in edges:
    if merge(vec[1], vec[2]):
        ans += vec[0]

print(ans)