#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[8] = {1,0,-1,0,-1,1,-1,1};
int dy[8] = {0,1,0,-1,-1,-1,1,1}; 
//int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1},{1,1}};
int board[51][51];
int vis[51][51];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(1){
		cin >> m >> n;
		if(m == 0 && n == 0) break;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> board[i][j];
			}
		}
		
		int cnt = 0;
	
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!board[i][j] || vis[i][j]) continue;
		  		cnt++;
		  		queue<pair<int,int>> q;
		  		vis[i][j] = 1;
		  		q.push({i,j});
		  		
		  		while(!q.empty()){
		  			auto cur = q.front(); q.pop();
		  			
		  			for(int idx = 0; idx < 8; idx++){
		  				int nx = cur.first + dx[idx];
		  				int ny = cur.second + dy[idx];
		  				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		  				if(!board[nx][ny] || vis[nx][ny]) continue;
		  				vis[nx][ny] = 1;
		  				q.push({nx,ny});
					}
				}
				
			}
		}
	
		cout << cnt << '\n';
		fill(&vis[0][0], &vis[n-1][m],0);
	}
	


}
