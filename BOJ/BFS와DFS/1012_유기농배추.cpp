#include <iostream> 
#include <queue> 
#include <algorithm> 

using namespace std;
#define X first
#define Y second
int t,m,n,k;
int x,y;
int board[51][51];
bool vis[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	
	
	while(t--){
		
		cin >> m >> n >> k;
		int num = 0;
		for(int i = 0; i < k; i++){
			cin >> y >> x;
			board[x][y] = 1;
		}
		queue<pair<int,int>> q;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j ++){
				if(board[i][j] == 0 or vis[i][j]) continue;
				num ++;
				vis[i][j] = 1;
				q.push({i,j});
				
				while(!q.empty()){
					pair<int,int> cur = q.front(); q.pop();
					for(int i = 0; i < 4; i++){
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];
						if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if(vis[nx][ny] || board[nx][ny] == 0) continue;
						vis[nx][ny] = 1;
						q.push({nx,ny});
					}
				}
			}
		} 
		cout << num <<'\n';
		fill(&board[0][0], &board[n-1][m],0);
		fill(&vis[0][0], &vis[n-1][m],0);
//		memset(board, false, sizeof(board));
//		memset(vis, 0, sizeof(vis));

	}
	
}
