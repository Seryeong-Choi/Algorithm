import sys
sys.setrecursionlimit(10**6)

n = int(sys.stdin.readline())
num = sys.stdin.readline().split()
m = int(sys.stdin.readline())
for i in num:
    i = int(i)

dp = [[-1 for i in range(2001)] for i in range(2001)]
for i in range(1, n + 1):
    dp[i][i] = 1

def solution(s, e):
    if s > e:
        return 1
    if dp[s][e] != -1:
        return dp[s][e]
    if num[s] != num[e]:
        dp[s][e] = 0
    else:
        dp[s][e] = solution(s + 1, e - 1)
    return dp[s][e]

for i in range(m):
    s, e = map(int, sys.stdin.readline().split())
    print(solution(s - 1, e - 1))
