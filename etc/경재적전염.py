from collections import deque

n, k = map(int,input().split())
data = []
graph = []
for i in range(n):
    graph.append(list(map(int,input().split())))
    for j in range(n):
        if graph[i][j] !=0:
            data.append((graph[i][j],0,i,j)) #바이러스종류,시간,위치xy
data.sort()
print("data",data)

target_s, target_x, target_y = map(int,input().split())



def bfs(data, graph):
    q = deque(data)
    print("q",q)
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    while q:
        virus, s, x, y = q.popleft()
        if s == target_s:
            break
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= 0 and nx < n and ny >= 0 and ny < n:
                if graph[nx][ny] == 0:
                    graph[nx][ny] = virus
                    q.append((virus, s+1, nx, ny))
                    
    return graph[target_x-1][target_y-1]
print(bfs(data, graph))