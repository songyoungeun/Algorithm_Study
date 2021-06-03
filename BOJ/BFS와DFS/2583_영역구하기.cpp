#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int m, n, k;
int x1,x2,y1,y2;
int board[101][101];
int vis[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
vector <int>v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int x = x1; x < x2; x++){
			for(int y = y1; y < y2; y++){
				board[y][x] = 1;
				vis[y][x] = 1; 
			}		
		}
	} 
	int num = 0; //영역의 수 

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] != 0 or vis[i][j]) continue; 
			num++; 
			queue<pair<int,int> > q;
			vis[i][j] = 1;
			q.push({i,j});
			int area = 0; //넓이  
			while(!q.empty()){
				area++;  
				pair<int,int> cur = q.front(); q.pop();
				for(int idx = 0; idx < 4; idx++){
					int nx = cur.X + dx[idx];
					int ny = cur.Y + dy[idx];
          			if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue; 
          			if(vis[nx][ny] || board[nx][ny] != 0) continue;
					vis[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
			v.push_back(area);			
		}
	}
	
	cout << num <<'\n';
	sort(v.begin(),v.end());
	for(int i = 0; i < num; i++) cout << v[i] << ' ';
	
}
