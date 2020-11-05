computers = [[1, 1, 0], [1, 1, 1], [0, 1, 1]]
# [[1, 1, 0,0], [1, 1, 0], [0, 0, 1]]
# [[1, 1, 0], [1, 1, 1], [0, 1, 1]]
n = 3
def dfs(computers, visited, start):
    starts = [start]
    while starts:
        print("2",starts)
        j = starts.pop()
        if visited[j] == 0:
            visited[j] = 1
        for i in range(0, len(computers)):
            if computers[j][i] == 1 and visited[i] == 0 :
             
                starts.append(i)


def solution(n, computers):
    answer = 0
    visited = [0 for _ in range(n)]
    start = 0
    while 0 in visited:
        if visited[start] == 0:
          
            dfs(computers, visited, start)
            answer += 1
       
        start += 1
    return answer
print(solution(n,computers))