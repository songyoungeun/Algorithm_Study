import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

n, m, start = map(int, input().split())
graph = [[] for i in range(n+1)]
print("g",graph)
distance = [INF] * (n + 1)
print("d",distance)
for _ in range(m):
    x, y, z = map(int,input().split())
    graph[x].append((y,z)) #a번 노드에서 b번 노드로 가는 비용이 z라는 의미

def dijkstra(start):
    q = []
    heapq.heappush(q, (0,start))
    print("h",heapq,q)
    distance[start] = 0
    while q:#큐가 비어있지 않다면
        print("wjile")
        #가장 최단 거리가 짧은 노드에 대한 정보를 꺼내기
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            print("con")
            continue
    
        #현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[now]:
            print("g",i)
            cost = dist + i[1]
            #현재노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
            print("qq",q)
dijkstra(start)
#도달할 수 있는 노드의 개수
count = 0
#도달할 수 있는 노드 중에서 가장 멀리 있는 노드와의 최단 거리
max_distance = 0
for d in distance:
    #도달할 수 있는 노드인 경우
    if d != INF:
        count += 1
        max_distance = max(max_distance, d)
#시작노드는 제외해야 하므로 count -1
print(count - 1, max_distance)