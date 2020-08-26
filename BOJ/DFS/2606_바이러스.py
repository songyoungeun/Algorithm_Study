node = int(input())
edge = int(input())
lst = [[0]*node for _ in range(node)]
visited = [False] * node

for i in range(edge):
    a, b = map(int,input().split())
    lst[a-1][b-1] = 1
    lst[b-1][a-1] = 1

def virus(v):
    visited[v] = True
    for i in range(node):
        if lst[v][i] == 1 and visited[i] == False:
            virus(i)
           
virus(0)

count = 0
for i in range(1, node):
    if visited[i] == True:
        count += 1
print(count)
#-----------------------
# from sys import stdin
# read = stdin.readline
# dic={}
# for i in range(int(read())):
#     dic[i+1] = set()

# for j in range(int(read())):
#     a, b = map(int,read().split())
#     dic[a].add(b)
#     dic[b].add(a)


# def dfs(start, dic):
#     for i in dic[start]:
#         if i not in visited:
#             visited.append(i)
#             dfs(i, dic)
# visited = []
# dfs(1, dic)

# print(len(visited)-1)