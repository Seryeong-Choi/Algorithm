import sys

n = int(sys.stdin.readline())
dp = [False for i in range(1001)] #True:win False:lose
dp[1] = True
dp[2] = False
dp[3] = True
dp[4] = True
for i in range(5, n + 1):
    if dp[i-1] and dp[i-3] and dp[i-4]:
        dp[i] = False
    else:
        dp[i] = True

if(dp[n]):
    print("SK")
else:
    print("CY")