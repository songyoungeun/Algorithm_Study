import sys
from collections import deque
r = sys.stdin.readline

def bfs(m,n,graph):
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == 0:
                queue.append([nx,ny])
                graph[nx][ny] = graph[x][y] +1

    ans = 0
    for i in graph:
        if 0 in i:
            return -1
        ans = max(ans,max(i))
    return ans-1
m,n = map(int,r().split())
graph = []
queue = deque([])
for i in range(n):
    graph.append(list(map(int,r().split())))
    for j in range(m):
        if graph[i][j] == 1:
            queue.append([i,j])
print(bfs(m,n,graph))
        