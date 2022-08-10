#include <string>
using namespace std;


int dx[] = {0,0,1,-1}; //오 왼 아래 위
int dy[] = {1,-1,0,0};
bool vis[15][15][4];

int reverse(int Dir){ //양방향 설정
    if(Dir == 0) return 1;
    else if(Dir == 1) return 0;
    else if(Dir == 2) return 3;
    else if(Dir == 3) return 2;
}
int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5; //초기값 
    for(int i = 0; i < dirs.length(); i++){
        char c = dirs[i];
        int nx, ny;
        int Dir;
        if(c == 'R'){
            Dir = 0;
            nx = x + dx[0];
            ny = y + dy[0];
        }
        else if(c == 'L'){
            Dir = 1;
            nx = x + dx[1];
            ny = y + dy[1];
        }
        else if(c == 'D'){
            Dir = 2;
            nx = x + dx[2];
            ny = y + dy[2];
        }
        else{ //U : 3
            Dir = 3;
            nx = x + dx[3];
            ny = y + dy[3];
        }
        if(nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;
        if(!vis[x][y][Dir] && !vis[nx][ny][reverse(Dir)]){
            //양방향으로 둘다 방문한적 없으면
            answer++;
            vis[x][y][Dir] = 1;
        }
        
        x = nx;
        y = ny;
    }
    return answer;
}
