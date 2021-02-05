#include <iostream>
using namespace std;

int board1[21][21]; //원본  
int board2[21][21];
int n;

void rotate(){ // board2를 시계 방향으로 90도 회전하는 함수
  int tmp[21][21];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      tmp[i][j] = board2[i][j];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      board2[i][j] = tmp[n-1-j][i];
}

void tilt(int dir){
  while(dir--) rotate();
  for(int i = 0; i < n; i++){
    int tilted[21] = {}; // board2[i]를 왼쪽으로 기울인 결과를 저장할 변수
    int idx = 0;
    for(int j = 0; j < n; j++){
      if(board2[i][j] == 0) continue;
      if(tilted[idx] == 0) 
        tilted[idx] = board2[i][j];
      else if(tilted[idx] == board2[i][j]) // 같은 값을 갖는 블록이 충돌할 경우
        tilted[idx++] *= 2;
      else // 다른 값을 갖는 블록이 충돌
        tilted[++idx] = board2[i][j];
        
    }
    for(int j = 0; j < n; j++) board2[i][j] = tilted[j]; 
    
  }

}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board1[i][j];

  int mx = 0;
  for(int tmp = 0; tmp < 1024; tmp++){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        board2[i][j] = board1[i][j];
    int brute = tmp;
    for(int i = 0; i < 5; i++){
      int dir = brute % 4; //dir :0왼 1아래 2오른 3위쪽 
      brute /= 4;
      tilt(dir);
    }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        mx = max(mx, board2[i][j]);
  }
  cout << mx;
}
