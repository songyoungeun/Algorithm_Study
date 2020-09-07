# import sys

# n,m,k = map(int, sys.stdin.readline().split())
# lst=list(map(int, sys.stdin.readline().split())) 

# lst.sort()
# first = lst[n-1] #가장 큰 수
# second = lst[n-2] #두 번째로 큰 수
# sum = 0
# while True :
#     for i in range(k) : 
#         if m == 0 :
#             break
#         sum += first
#         m -= 1
#     if m == 0 : 
#         break
#     sum += second
#     m -= 1
# print(sum)

import sys

n,m,k = map(int, sys.stdin.readline().split())
lst=list(map(int, sys.stdin.readline().split())) 

lst.sort()
first = lst[n-1] #가장 큰 수
second = lst[n-2] #두 번째로 큰 수

count = int(m /(k + 1)) * k + m % (k + 1)
count += m % (k + 1)

sum = 0
sum += (count) * first
sum += (m - count) * second

print(sum)
