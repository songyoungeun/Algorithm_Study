from bisect import bisect_left, bisect_right
words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]	
queries = ["fro??", "????o", "fr???", "fro???", "pro?"]	
# result		[3, 2, 4, 1, 0]
def count_by_range(a, left_value, right_value):
    right_index = bisect_right(a, right_value)
    left_index = bisect_left(a, left_value)

    return right_index - left_index

array = [[] for _ in range(10001)]
reversed_array=[[] for _ in range(10001)]

def solution(words, queries):
    answer = []
    for word in words:
        array[len(word)].append(word)
        reversed_array[len(word)].append(word[::-1]) #단어를 뒤집어서 저장 -> 접미사에 ?가 오는 경우때문

    for i in range(10001): #이진탐색을 위해 정렬
        array[i].sort()
        reversed_array[i].sort()

    for q in queries:
        if q[0] != '?': #접미사에 ?붙은 경우
            res = count_by_range(array[len(q)], q.replace('?','a'), q.replace('?','z'))
        else: #접두사에 ?붙은 경우
            res = count_by_range(reversed_array[len(q)], q[::-1].replace('?','a'), q[::-1].replace('?','z'))
        answer.append(res)
    return answer
print(solution(words, queries))