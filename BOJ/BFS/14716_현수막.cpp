#include <iostream>
#include <queue>
#include <algorithm>

#define x first
#define y second 
using namespace std;

int m, n;
int board[251][251];
bool vis[251][251];
int dx[8] = {1,0,-1,0,-1,1,-1,1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	queue<pair<int,int>>q;

	int num = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(vis[i][j] || !board[i][j]) continue;
			q.push({i,j});
			vis[i][j] = 1;
			num++;
			while(!q.empty()){
				auto cur = q.front(); q.pop();
				for(int idx = 0; idx < 8; idx++){
					int nx = cur.x + dx[idx];
					int ny = cur.y + dy[idx];
					if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if(!board[nx][ny] || vis[nx][ny]) continue;
					q.push({nx,ny});
					vis[nx][ny] = 1;
					
				}
			}
		}
	}
	cout << num;	
}
