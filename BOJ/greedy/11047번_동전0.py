import sys

n, k = map(int,input().split())
coin = [int(input()) for i in range(n)]
coin.reverse()
sum = 0

for i in coin :
    if k >= i :
        sum += k // i
        k %= i
        if k == 0:
            print(sum)
            break

# for i in coin :
#     if k >= i :
#         sum += k // i
#         k %= i
#     else :
#         continue
#     if k == 0:
#         print(sum)
#         break
