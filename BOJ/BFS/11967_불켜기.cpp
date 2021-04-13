#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define x first
#define y second
int n,m;
int x,y,a,b;
int board[101][101];
bool vis[101][101];

vector<pair<int,int>> v1[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> x >> y >> a >> b;
		v1[x-1][y-1].push_back({a-1,b-1});
		
	}
	while(1){
		memset(vis,0,sizeof(vis));
		queue<pair<int,int>>q;
		q.push({0,0});
		vis[0][0] = 1;
		board[0][0] = 1;
		bool flag = false;
		while(!q.empty()){
			auto cur = q.front(); q.pop();
			if(!v1[cur.x][cur.y].empty()){
				for(int i = 0; i < v1[cur.x][cur.y].size(); i++){
					auto c = v1[cur.x][cur.y][i];
					board[c.x][c.y] = 1;
				}
				v1[cur.x][cur.y].clear();
				flag = true;
			}
		
			for(int idx = 0; idx < 4; idx++){
				int nx = cur.x + dx[idx];
				int ny = cur.y + dy[idx];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if(board[nx][ny]  == 1 and !vis[nx][ny]){
					q.push({nx,ny});
					vis[nx][ny] = 1;
				}
			}
		}
		if(!flag) break;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j]) cnt++;
		}
	}
	cout << cnt;
	
//	cout << v1[1][1][0].first <<v1[1][1][0].second;


	
	
	
}
