import sys
def solution(board, moves):
    answer = 0
    stack = []
    for i in moves:
        for j in range(len(board)): 
            if board[j][i-1] == 0: #위 아래로 크레인이 움직임 
                pass
            else:
                stack.append(board[j][i-1]) #인형 있으면 잡아 바구니에 넣기
                board[j][i-1] = 0
                break
        if len(stack) >1 and stack[-1] == stack[-2]: #같은 인형 연속해 있다면 터짐
            stack.pop(-1)
            stack.pop(-1)
            answer += 2
    return answer

# board =	[[0, 0, 0, 0, 0],
#          [0, 0, 1, 0, 3], 
#          [0, 2, 5, 0, 1], 
#          [4, 2, 4, 4, 2],
#          [3, 5, 1, 3, 1]]
# moves = [1, 5, 3, 5, 1, 2, 1, 4]
num = int(input())
board = [[int(x) for x in input().split()]for y in range(num)]
moves = list(map(int,input()))

print(solution(board,moves))