from itertools import permutations

def solution(n, weak, dist):
    length = len(weak)
    for i in range(length):
        #길이를 2배로 늘려서 원형을 일자 형태로 변형
        weak.append(weak[i] + n)
    answer = len(dist) + 1 #투입할 친구 수의 최솟값을 찾아야 하므로 +1

    for start in range(length):
        #친구를 나열하는 모든 경우의 수 각각에 대해 확인
        for friends in list(permutations(dist, len(dist))):
            count = 1 #투입할 친구의 수
            #해당 친구가 점검할 수 있는 마지막 위치
            position = weak[start] + friends[count - 1]
            #시작점부터 모든 취약 지점을 확인
            for index in range(start, start + length):
                if position < weak[index]:
                    #점검할 수 있는 위치를 벗어나는 경우
                    count += 1 # 새로운 친구 투입
                    if count > len(dist): # 더 투입이 불가능한 경우 종료
                        break
                    position = weak[index] + friends[count - 1]
            answer = min(answer, count)
    if answer > len(dist):
        return -1
    return answer


n = 12
weak = [1, 3, 4, 9, 10]	
dist =	[3, 5, 7]
print(solution(n, weak, dist))

# [1, 5, 6, 10]	[1, 2, 3, 4]	
# [1, 3, 4, 9, 10]	[3, 5, 7]	
