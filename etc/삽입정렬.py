#삽입정렬------------------------
# array = [7,5,9,0,3,1,6,2,4,8]

# for i in range(1, len(array)):
#     for j in range(i, 0, -1):
#         print("j",j)
#         if array[j] < array[j-1]:
#             print("1")
#             array[j], array[j-1] = array[j-1], array[j]
#             print("2")
#         else :
#             break
# print(array)
#퀵정렬----------
# array = [5,7,9,0,3,1,6,2,4,8]
# def quick_sort(array):
#     if len(array) <= 1:
#         return array
#     pivot = array[0]
#     tail = array[1:]

#     left_side = [x for x in tail if x <= pivot]
#     print("left",left_side)
#     right_side = [x for x in tail if x > pivot]
#     print("right_side",right_side)

#     return quick_sort(left_side) + [pivot] + quick_sort(right_side)

# print(quick_sort(array))
#-----
n, k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

a.sort()
b.sort()

for i in range(k):
    if a[i] < b[-i] :
        a[i] = b[-i]
result = 0
print("a",a)
for i in range(len(a)):
    result += a[i]
print(result)