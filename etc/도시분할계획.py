def find_parent(parent, x):
    print("xxx",parent[x], x)
    if parent[x] != x:
        print("x",parent[x], x)
        parent[x] = find_parent(parent,parent[x])
        
    print("xxxxxx",parent[x], x)
    return parent[x] 

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a< b:
        parent[b] = a
    else:
        parent[a] = b

v, e = map(int, input().split())
parent = [0] * (v + 1)
#모든 간선을 담을 리스트와 최종비용을 담을 변수
edges =[]
result = 0

for i in range(1, v + 1):
    parent[i] = i
for _ in range(e):
    a, b, cost = map(int,input().split())
    edges.append((cost, a, b))
edges.sort() #간선을 비용 순으로 정렬
print("edges",edges)
last = 0 #최소 신장 트리에 포함되는 간선 중에서 가장 비용이 큰 간선

for edge in edges:
    cost, a, b = edge
    #사이클이 발생하지 않는 경우에만 집합에 포함
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        print("parent",parent)
        result += cost
        last = cost
        print("re la",result,  last)
print(result - last)