answer = 0
def DFS(idx, numbers, target, value):
    global answer
    N = len(numbers)
    if(idx== N and target == value):
        print("1",idx, N, target, value)
        answer += 1
        return
    if(idx == N):
        print("2",idx , N)
        return
    print("3",idx+1,numbers,target,value+numbers[idx])
    DFS(idx+1,numbers,target,value+numbers[idx])
    print("4",idx+1,numbers,target,value-numbers[idx])
    DFS(idx+1,numbers,target,value-numbers[idx])
    


def solution(numbers, target):
    global answer
    DFS(0,numbers,target,0)
    return answer
numbers =[1, 1, 1, 1, 1]
target = 3	
print(solution(numbers, target))