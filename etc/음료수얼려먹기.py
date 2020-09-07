n, m = map(int, input().split())
array = []
for i in range(n):
   array.append(list(map(int,input())))

def dfs(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False
    if array[x][y] == 0:
        array[x][y] = 1
        dfs(x - 1, y) #상
        dfs(x + 1, y) #하
        dfs(x, y - 1) #좌
        dfs(x, y + 1) #우
        return True
    return False
    


result = 0
#모든 노드에 대하여 
for i in range(n):
    for j in range(m):
        if dfs(i, j) == True:
            result += 1
print(result)