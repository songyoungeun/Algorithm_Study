#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int n,m;
int board[505][505];
bool vis[505][505];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
  	for(int j = 0; j < m; j++){
  		cin >> board[i][j];
	  }
  }
  int cnt = 0, mx = 0;
  
  for(int i = 0; i < n; i++){
  	for(int j = 0; j < m; j++){
  		if(!board[i][j] or vis[i][j]) continue;
  		cnt++;
  		queue<pair<int,int>> q;
  		vis[i][j] = 1;
  		q.push({i,j});
  		int area = 0;
  		while(!q.empty()){
  			auto cur = q.front(); q.pop();
  			area++;
  			for(int idx = 0; idx < 4; idx++){
  				int nx = cur.X + dx[idx];
  				int ny = cur.Y + dy[idx];
  				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
  				if(!board[nx][ny] || vis[nx][ny]) continue;
  				vis[nx][ny] = 1;
  				q.push({nx,ny});
			  }
		}
		mx = max(mx, area);
	}
  }
  cout << cnt << '\n' << mx;
}

