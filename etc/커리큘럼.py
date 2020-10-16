from collections import deque
import copy

n = int(input())
#모든 노드에 대한 진입차수는 0으로 초기화
indegree = [0] * (n+1)
#각 노드에 연결된 간선 정보를 담기 위한 연결 리스트() 초기화
graph = [[] for i in range(n+1)]
time = [0] * (n+1)

for i in range(1,n+1):
    data = list(map(int, input().split()))
    time[i] = data[0]
    for x in data[1:-1]:
        print("x",x)
        indegree[i] += 1
        graph[x].append(i)
        print("gr",graph)

def topology_sort(): #위상정렬 함수
    result = copy.deepcopy(time) #알고리즘 수행 결과를 담을 리스트 복사
    print("Re",result)
    q = deque()

    for i in range(1, n+1): #진입차수가 0인 노드를 큐에 삽입
        if indegree[i] == 0:
            q.append(i)
    while q:
        now = q.popleft()
        for i in graph[now]:
            print("result",result[i], result[now]+ time[i])
            result[i] = max(result[i], result[now]+ time[i])

            indegree[i] -= 1
            if indegree[i] == 0:
                q.append(i)
    for i in range(1, n+1):
        print(result[i])

topology_sort()