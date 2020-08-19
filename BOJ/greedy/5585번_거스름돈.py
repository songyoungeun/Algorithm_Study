# import sys
# result = 0
# m = int(sys.stdin.readline())
# m = 1000 - m

# result += m // 500
# m = m % 500

# result += m // 100
# m = m % 100

# result += m // 50
# m = m % 50

# result += m // 10
# m = m % 10

# result += m // 5
# m = m % 5

# result += m // 1

# print(result)
import sys

n = int(sys.stdin.readline())
n = 1000 - n
count = 0

# 큰 단위의 화폐부터 차례대로 확인하기
coin_types = [500, 100, 50, 10, 5, 1]

for coin in coin_types:
    count += n // coin # 해당 화폐로 거슬러 줄 수 있는 동전의 개수 세기
    n %= coin

print(count)