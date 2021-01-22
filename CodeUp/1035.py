# a = input()
# print(ord(a)) #문자의 아스키 코드 값을 돌려주는 함수

a, b, c = map(int, input().split())
n = a + b + c
print(n)

print("%.1f"%(n/3))