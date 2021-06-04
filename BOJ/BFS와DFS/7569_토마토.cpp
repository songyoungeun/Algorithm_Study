#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int n,m,h;
int dist[101][101][101];
int board[101][101][101];
int dz[6] = {1,-1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {0,0,0,0,1,-1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> h;
	
	queue<pair<pair<int, int>,int>> Q;
	for(int k = 0; k < h; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> board[i][j][k];
				if(board[i][j][k] == 1) Q.push({{i,j},k});
					
				if(board[i][j][k] == 0) dist[i][j][k] = -1;
			
			}
		}	
	}


	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int i  = 0; i < 6; i++){
			int nx = cur.first.first + dx[i];
			int ny = cur.first.second + dy[i];	
			int nz = cur.second + dz[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(dist[nx][ny][nz] >= 0) continue;
			
			dist[nx][ny][nz] = dist[cur.first.first][cur.first.second][cur.second]+1;
			Q.push({{nx,ny},nz});
		}

	}
	int ans = 0;
	for(int k = 0; k < h; k++){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(dist[i][j][k] == -1){
					cout<<-1<<'\n';
					return 0;
				}
				else{
					ans = max(ans,dist[i][j][k]);
				}
			}
		}
	}
	
	cout << ans <<'\n';
}
	
