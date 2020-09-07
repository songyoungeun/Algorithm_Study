#stack사용
n = int(input())

for i in range(n):
    stack =[]
    result = ''
    line = input()
    for char in line:
        if char == ' ':
            while stack:
                result += stack.pop()
            result += ' '
        else:
            stack.append(char)
    while stack:
        result += stack.pop()
    print(result)

# ---------------------
# t = int(input())
# for i in range(t):
#     str = input()
#     li = list(str.split(' '))
#     for j in li:
#         print(j[::-1],end=' ')
#     print()


