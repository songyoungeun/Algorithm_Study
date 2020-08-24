n, m = map(int, input().split())

#방문 위치 저장 앱 생성해 초기화
d = [[0]*m for _ in range(n)] 

x, y, direction = map(int, input().split())
d[x][y] = 1 #현재 좌표 방문 처리

array = []
#맵 정보 입력
for i in range(n):
    array.append(list(map(int,input().split())))
#북동남서 
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def turn_left():
    global direction
    direction -= 1
    if direction == -1:
        direction = 3
#시뮬레이션 시작
count = 1
turn_time = 0
while True:
    #왼쪽으로 회전
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]
    #회전한 이후 정명에 가보지 않은 칸 존재하는 경우
    if d[nx][ny] == 0 and array[nx][ny] == 0:
        d[nx][ny] = 1
        x = nx
        y = ny
        count += 1
        turn_time = 0
        continue
    else: #회전한 이후 정면에 가보지 않은 칸이 없거나 바다일 경우
        turn_time += 1
    #네 방향 모두 갈 수 없는 경우
    if turn_time == 4:
        nx = x - dx[direction]
        ny = y - dy[direction]
        #뒤로 갈 수 있다면 이동
        if array[nx][ny] == 0:
            x = nx
            y = ny
        else: #뒤가 바다로 막혀있는 경우
            break
        turn_time = 0
print(count)
