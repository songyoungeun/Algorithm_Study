n, k = map(int, input().split())
c = []
for i in range(n):
    c.append(int(input()))

dp = [10001] * (k + 1)
dp[0] = 0

for i in range(n):
    for j in range(c[i], k + 1):
        if dp[j - c[i]] != 10001:
            dp[j] = min(dp[j], dp[j - c[i]]+ 1)
if dp[k] == 10001:
    print(-1)
else:
    print(dp[k]) 