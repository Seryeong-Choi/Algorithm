import sys

n = int(sys.stdin.readline())
nums = sys.stdin.readline().split()
for i in range(n):
    nums[i] = int(nums[i])
result = nums[n - 1]

dp = [0 for i in range(21)]
dp[nums[0]] += 1
for i in range(1, n - 1):
    newdp = [0 for j in range(21)]
    for j in range(21):
        if dp[j] > 0:
            if j + nums[i] >= 0 and j + nums[i] <= 20:
                newdp[j + nums[i]] += dp[j]
            if j - nums[i] >= 0 and j - nums[i] <= 20:
                newdp[j - nums[i]] += dp[j]
    dp = newdp

print(dp[result])