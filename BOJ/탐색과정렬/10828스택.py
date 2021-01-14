import sys
input = sys.stdin.readline
stack = []
n = int(input())
for _ in range(n):
    a = input()
    a = a[:-1]
    
    if a.split()[0] == 'push':
        stack.append(a.split()[1])
    elif 'pop' == a:
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    elif 'size' == a:
        print(len(stack))
    elif 'empty' == a:
        if len(stack) == 0 :
            print(1)
        else:
            print(0)
    elif 'top' == a:
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])