import sys

n = int(sys.stdin.readline())
bongi = 0
while True:
    if n % 5 == 0:
        bongi += n // 5
        n %= 5
        print(bongi)
        break
    n -= 3
    bongi +=1
    if n < 0 :
        print("-1")
        break


