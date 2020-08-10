import sys
result = 0
m = int(sys.stdin.readline())
m = 1000 - m

result += m // 500
m = m % 500

result += m // 100
m = m % 100

result += m // 50
m = m % 50

result += m // 10
m = m % 10

result += m // 5
m = m % 5

result += m // 1

print(result)