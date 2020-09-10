
def possible(answer):
    for x, y, stuff in answer:
        if stuff == 0: # 기둥 설치시
            # 바닥위 혹은 보의 한쪽 끝부분 위 혹은 다른 기둥 위라면 정상
            if y == 0 or [x -1, y, 1] in answer or [x, y, 1] in answer or [x, y-1, 0] in answer:
                continue
            return False
        elif stuff == 1:
            if [x, y-1, 0] in answer or [x+1, y-1, 0] in answer or ([x-1, y, 1] in answer and [x+1, y, 1] in answer):
                continue
            return False
    return True
def solution(n, build_frame):
    print("bb",build_frame)
    answer = []
    for frame in build_frame:
        x, y, stuff, operate = frame
        if operate == 0: #삭제할때
            answer.remove([x, y, stuff]) #일단 삭제
            if not possible(answer): #가능한 구조물인지 확인
                answer.append([x, y, stuff]) #불가능한 구조물이면 다시 설치
                print("re",answer)
        if operate == 1: #설치할때
            answer.append([x, y, stuff]) #일단 설치
            print("aa",answer)
            if not possible(answer):# 가능한지 확인
                answer.remove([x, y, stuff])# 불가능이라면 삭제
                print("remove?",answer)
    print("hi",answer)
    return sorted(answer)

n = 5
build_frame = [[1,0,0,1],
                [1,1,1,1],
                [2,1,0,1],
                [2,2,1,1],
                [5,0,0,1],
                [5,1,0,1],
                [4,2,1,1],
                [3,2,1,1]]
print(solution(n, build_frame))