import heapq
INF = int(1e9)

n, m = map(int, input().split())
graph = [[INF] * (n + 1) for i in range(n + 1)]


#자기자신으로 가는 비용은 0
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0
for _ in range(m):
    a, b = map(int,input().split())
    graph[a][b] = 1
    graph[b][a] = 1
x, k = map(int,input().split())

#점화식에 따라 플로이드 워셜 알고리즘 수행
for k in range(1, n +1):
    print(k)
    for a in range(1, n +1):
        for b in range(1, n +1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])
print(graph)
distance = graph[1][k] + graph[k][x]

if distance >= INF:
    print("-1")
else:
    print(distance)