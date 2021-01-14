#이분탐색
import sys
input = sys.stdin.readline

n = input()
print(n)
a = sorted(map(int,input().split()))
m = input()
b = map(int,input().split())

def binary(i,a,start,end):
    if start > end:
        return 0
    j = (start+end) // 2
    if i == a[j]:
        return 1
    elif i < a[j]:
        return binary(i,a,start,j-1)
    else:
        return binary(i,a,j+1,end)
for i in b:
    start = 0
    end = len(a) - 1
    print(binary(i,a,start,end))

#집합 자료형을 통한 포함 여부 확인

# n = input()
# a = set(input().split())
# m = input()
# b = input().split()

# for i in b:
#     print(1 if i in a else 0)

