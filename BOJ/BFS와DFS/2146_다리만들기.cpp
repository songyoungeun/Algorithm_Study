#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define x first
#define y second
int n;
int board[101][101];
bool vis[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(int cnt){
	queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(board[i][j] == cnt){
    			vis[i][j] = 1;
    			q.push({i,j});
			}
		}	
	}
    int dist = 0;
    while(!q.empty()){
    	int qsize = q.size();
		
		for(int i = 0; i < qsize; i++){
			auto cur = q.front(); q.pop();
			for(int idx = 0; idx < 4; idx++){
				int nx = cur.x + dx[idx];
				int ny = cur.y + dy[idx];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if(board[nx][ny] && board[nx][ny] != cnt) return dist; //다른 섬에 도착할 경우 반환  
				else if(!vis[nx][ny] && !board[nx][ny]){
					//방문하지 않은 바다칸이면  
					vis[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
			
		}
		dist++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)	
			cin >> board[i][j];
	queue<pair<int,int>>q;
	int cnt = 0;
	for(int i = 0; i < n; i++){ // 몇번 섬인지 표시  
		for(int j = 0; j < n; j++){
			if(board[i][j] == 1 && !vis[i][j]){
				cnt++;
				q.push({i,j});
				vis[i][j] = 1;
				board[i][j] = cnt;
				while(!q.empty()){
					auto cur = q.front(); q.pop();
					for(int idx = 0; idx < 4; idx++){
						int nx = cur.x + dx[idx];
						int ny = cur.y + dy[idx];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(board[nx][ny] == 0 || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						board[nx][ny] = cnt;
						q.push({nx,ny});
					}
				}
					
			}
		}
	}
	int res = 987654321;
	for(int i = 1; i < cnt; i++){
		memset(vis,0,sizeof(vis));
		res = min(res,bfs(i));
	}
	cout << res;

} 
