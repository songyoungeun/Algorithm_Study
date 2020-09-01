n, m = map(int, input().split())
a = [list(map(int,input())) for _ in range(n)]
b = [list(map(int,input())) for _ in range(n)]

def flip(x,y):
    print("d",x,y)
    for i in range(x,x+3):
        for j in range(y,y+3):
            a[i][j] = 1 - a[i][j]

def checkEquality():
    for i in range(n):
        for j in range(m):
            if a[i][j] !=b[i][j]:
                return 0
    return 1

cnt = 0
for i in range(0,n-2):
    for j in range(0,m-2):
        if a[i][j] !=b[i][j]:
            flip(i,j)
            cnt+=1

if checkEquality():
    print(cnt)
else:
    print(-1)
