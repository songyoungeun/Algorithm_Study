# import sys
# input = sys.stdin.readline

# n = int(input())
# lst = []
# for i in range(n):
#     lst.append(int(input()))
#     print("1",lst)
# lst.sort()
# for i in lst:
#     print(i)
#버블 정렬
N = int(input())

numbers = []

for _ in range(N) : 
    numbers.append(int(input()))
print("1",numbers)
# Bubble Sort
for i in range(len(numbers)) : 
    for j in range(len(numbers)) : 
        if numbers[i] < numbers[j] : 
            numbers[i], numbers[j] = numbers[j], numbers[i]
            
for n in numbers : 
    print(n)