input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0])) - int(ord('a')) + 1
#ord(c)는 문자의 아스키 코드 값을 돌려주는 함수이다.

#나이트가 갈 수 있는 방향 8가지 정의
steps = [
        (-2, -1), (-1, -2), (1, -2), (2, -1),
        (2, 1), (1, 2), (-1, 2), (-2, 1)
]

result = 0
for step in steps :
    next_row = row + steps[0]
    next_column = column + steps[1]

    if next_row >= 1 and next_row <= 8 and next_column >= 1 and next_column <= 8:
        result +=1
        
print(result)