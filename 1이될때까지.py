n, k = map(int, input().split())
count = 0
#1-------------------------------------
# if n % k == 0:
#     while n > 1:
#         n = n // k
#         count +=1
# else:
#     n = n - 1
#     count +=1
#     while n > 1:
#         n = n // k
#         count +=1
# print(count)
#2-------------------------------------
# while n >= k :
#     while n % k != 0:
#         n -= 1
#         count +=1
#     n //= k
#     count +=1

# while n > 1 :
#     n -= 1
#     count +=1

# print(count)
#3-------------------------------------
while True:
    target = (n // k) * k
    print("t",target)
    count += (n - target)
    print("c",count)
    n = target
    print("n",n)

    if n < k :
        break
    print("c555",count)
    count +=1
    print("c2",count)
    n //= k
    print("n2",n)
count += (n - 1)
print("c3",count)
print(count)