import sys

n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n + 1)]
rank = [1 for i in range(n + 1)]

def find(u):
    if u == parent[u]:
        return u
    else:
        parent[u] = find(parent[u])
        return parent[u]

for i in range(m):
    oper, a, b = map(int, sys.stdin.readline().split())
    a_parent = find(a)
    b_parent = find(b)
    if oper == 0:
        if a_parent == b_parent:
            continue
        else:
            if rank[a_parent] > rank[b_parent]:
                parent[b_parent] = a_parent
            elif rank[b_parent] > rank[a_parent]:
                parent[a_parent] = b_parent
            else:
                parent[b_parent] = a_parent
                rank[a_parent] += 1
    elif oper == 1:
        if parent[a] == parent[b]:
            print("YES")
        else:
            print("NO")