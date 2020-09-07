import sys
result = 0
n ,m = map(int,sys.stdin.readline().split())
#1-------------------------------------
# matrix = [sys.stdin.readline().split() for i in range(n)]

# for i in range(n):
#     min_value = 10001
#     for j in range(m):
#         min_value = min(min_value, int(matrix[i][j]))

#     result = max(result, min_value)
    
# print(result)
#2-------------------------------------
result = 0
for i in range(n):
    data = list(map(int,input().split()))
    min_value = min(data)
    result = max(result, min_value)
print(result)    
#3------------------------------------
# result = 0
# for i in range(n):
#     data = list(map(int,input().split()))
#     min_value = 10001
#     for a in data :
#         min_value = min(min_value, a)
#     result = max(result, min_value)

# print(result)  
