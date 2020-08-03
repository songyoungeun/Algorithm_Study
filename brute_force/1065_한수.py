import sys 

def Hansu(N):
    hansu = 0

    if N < 100 : # 1부터 99까지는 모두 한수
        return N 
    else:
        for n in range(100, N+1) :
            nums = list(map(int, str(n))) # 숫자를 자릿수대로 분리 
            if nums[0] - nums[1] == nums[1] - nums[2] : #등차수열이면
                hansu+=1
        return 99+hansu

N = int(sys.stdin.readline())
print(Hansu(N))
