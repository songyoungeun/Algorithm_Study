n = int(input())
t = []
a= []
for i in range(n):
    t = input()
    tmp = list(t)
    sum = 0
    for j in t:
        if j == '(':
            sum += 1
        elif j == ')':
            sum -= 1
        if sum < 0:
            print("NO")
            break

    if sum == 0:
        print("YES")
    elif sum > 0:
        print("NO")
# num = int(input())

# for i in range(num):
#     vps = list(input())
#     while len(vps) != 0:
#         if vps[0] == ')':
#             print('NO')
#             break
#         else:
#             if ')' in vps:
#                 vps.remove(')')
#                 vps.remove('(')
#             else:
#                 print("NO")
#                 break
#     if len(vps)==0:

