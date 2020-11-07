# 틀린답
n = int(input())

if n == 1:
    print("False")

for i in range(2,n):
    if n % i == 0  :
        print("False")
        break
    else:
        print("True")
        break
# -------------
# 맞는답
n = int(input())
b = 0
if n == 1:
    print("False")

for i in range(2,n):
    if n % i == 0  :
        b = 1
        break
if b == 0 :
    print("True")
else:
	print("False")
	

		
		