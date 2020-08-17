# from collections import Counter
# def solution(participant, completion):
#     answer = Counter(participant) - Counter(completion)


#     return list(answer)[0]

def solution(participant, completion):
    answer = ''
    temp = 0
    dic = {}
    for part in participant:
        dic[hash(part)] = part
        temp += int(hash(part))
    for com in completion:
        temp -= hash(com)
    answer = dic[temp]
    return answer
participant = ["marina", "josipa", "nikola", "filipa","filipa"]

completion = ["josipa", "filipa", "marina", "nikola"]


	
print(solution(participant, completion))