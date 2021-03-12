#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define X first
#define Y second

int n;
int board[105][105];
int vis[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(){
	int area = 0;
	queue<pair<int,int>>q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(vis[i][j]) continue;
			area++;
			vis[i][j] = 1;
			q.push({i,j});
			while(!q.empty()){
				auto cur = q.front(); q.pop();
				for(int idx = 0; idx < 4; idx++){
					int nx = cur.X + dx[idx];
					int ny = cur.Y + dy[idx];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					q.push({nx,ny});
				}	
			}
			
		}
	}

	return area;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int h = 0;
	int he;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> he;
			board[i][j] = he;
			h = max(h,he);
		}
	}

	int a = 0;
	for(int i = 0; i <= h; i++){
		memset(vis, false, sizeof(vis));
		for(int x = 0; x < n; x++){
			for(int y = 0; y < n; y++){
				if(board[x][y] <= i){
					vis[x][y] = 1;
				}
			}
		}
		a = max(a, bfs());
	}

	cout << a;
}
