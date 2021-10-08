import math
import itertools
def chk_prime(n):
    if n < 2 : return False
    to = int(math.sqrt(n)) +1;
    for i in range(2,to):
        if n % i == 0 : 
            return False
    return True

def solution(numbers):
    candidate = set()
    for i in range(len(numbers)):
        number = set(map(int,map(''.join, itertools.permutations(numbers,i+1))));
        candidate |= number #합집합
        
    answer = 0
    candidate = list(candidate)
    for n in candidate:
        if chk_prime(n):
            answer += 1
    return answer