import sys

def dfs(v):
    print(v,end=' ')
    visited[v] = 1
    for i in range(1, N+1):
        if visited[i] == 0 and matrix[v][i] == 1:
            dfs(i) #재귀사용

def bfs(v):
    queue = [v] 
    visited[v] = 0 # dfs에서 1로 해줬기에 방문 시 0으로 설정
    while (queue):  
        v = queue.pop(0)	
        print(v,end=' ')
	
        for i in range(1, N+1):
            if visited[i] == 1 and matrix[v][i] == 1:
                queue.append(i)
                visited[i] =0

N, M, V = map(int, sys.stdin.readline().split())

matrix = [[0] * (N + 1) for i in range(N + 1)]
visited =  [0 for i in range(N + 1)] #방문처리

for i in range(M):
    a, b = map(int, sys.stdin.readline().split())
    matrix[a][b] = 1
    matrix[b][a] = 1

dfs(V)
print()
bfs(V)