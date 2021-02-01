#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define X first;
#define Y second;

int dx[4] = {1,0,-1,0}; //남 동 북 서  
int dy[4] = {0,1,0,-1};
int n,m;
int board1[10][10]; //사무실 모양 
int board2[10][10]; //cctv방향 저장후 감시 영역에 걸리는 영역 7로 바 꿈  
vector<pair<int,int>> cctv; // cctv의 좌표 담아  

bool OOB(int a, int b){
	return a < 0 || a >= n || b < 0 || b >= m;
}
void upd(int x, int y, int dir){
	dir %= 4;
	while(1){
		x += dx[dir];
		y += dy[dir];
		if(OOB(x,y) || board2[x][y] == 6)return;
		if(board2[x][y] != 0)continue; //cctv있을 때ㅠ  
		board2[x][y] = 7;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int mn = 0; //사각지대최소크기  
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board1[i][j];
			if(board1[i][j] != 0 && board1[i][j] != 6) //cctv찾으면 넣어줘  
				cctv.push_back({i,j});
			if(board1[i][j] == 0) mn++;
		}		
	}
	for(int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++){ // 1<<(2*cctv.size()) = 4^cctv.size()
		for(int i = 0; i < n; i++)
			for(int j = 0;j < m; j++)
				board2[i][j] = board1[i][j];
		int brute = tmp;
		for(int i = 0; i < cctv.size(); i++){
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].X; //tie(x,y) = cctv[i];
			int y = cctv[i].Y;
			if(board1[x][y] == 1){
				upd(x,y,dir);
			}
			else if(board1[x][y] == 2){
				upd(x,y,dir); 
				upd(x,y,dir+2);
			}
			else if(board1[x][y] == 3){
		        upd(x,y,dir);
		        upd(x,y,dir+1);
		      }
		    else if(board1[x][y] == 4){
		        upd(x,y,dir);
		        upd(x,y,dir+1);
		        upd(x,y,dir+2);
		      }
		    else{ // board1[x][y] == 5
		        upd(x,y,dir);
		        upd(x,y,dir+1);
		        upd(x,y,dir+2);
		        upd(x,y,dir+3);
		      }
		    }
		    int val = 0;
		    for(int i = 0; i < n; i++)
		      for(int j = 0; j < m; j++)
		        val += (board2[i][j]==0);
		    mn = min(mn, val);
	}
  	 cout << mn;
			
}
		
