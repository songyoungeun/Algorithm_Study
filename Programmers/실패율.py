n = 5	
stages = [2, 1, 2, 6, 2, 4, 3, 3]	

def solution(n, stages):
    answer = []
    length = len(stages)
    for i in range(1, n+1):
        count = stages.count(i)

        if length == 0:
            fail = 0
        else:
            fail = count / length
        
        answer.append((i, fail))
        length -= count 
    answer = sorted(answer, key = lambda t: t[1], reverse=True)

    answer = [i[0] for i in answer]
    return answer
 
print(solution(n, stages))

#----------------------
# def solution(N, stages):
#     result = {}
#     denominator = len(stages)
#     for stage in range(1, N+1):
#         if denominator != 0:
#             count = stages.count(stage)
#             result[stage] = count / denominator
#             print("re",result)
#             denominator -= count
#         else:
#             result[stage] = 0
#     print("rr",result[1])
#     return sorted(result, key=lambda x : result[x], reverse=True)
    
# print(solution(n, stages))