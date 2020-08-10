import sys
sum = 0

for i in range(5):
    a = int(sys.stdin.readline())
    if a< 40 :
        sum += 40
    else:
        sum += a
    
print(int(sum / 5))
