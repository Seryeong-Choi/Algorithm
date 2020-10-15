import sys
sys.setrecursionlimit(10**6)

a, b = map(int, sys.stdin.readline().split())
dp = [[-1 for i in range(b + 1)] for j in range(a + 1)]

def solution(n, k):
    if n < 1:
        return 0
    if n == k or k == 0:
        return 1
    if k == 1:
        return n
    if dp[n][k] != -1:
        return dp[n][k]

    dp[n][k] = (solution(n - 1, k) + solution(n - 1, k - 1)) % 10007
    return dp[n][k]

print(solution(a, b))