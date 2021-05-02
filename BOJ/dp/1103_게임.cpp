#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int board[51][51];
bool vis[51][51];
int dp[51][51];
bool circle;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

//int cmp(int a, int b){ if(a > b) return a; return b;}
int dfs(int x, int y){
	
	if(x < 0 || x >= n || y < 0 || y >= m) return 0;
	if(board[x][y] == 0)return 0;
	if(vis[x][y]){
		circle = 1;
		return -1;
	}	
	if(dp[x][y] != -1) return dp[x][y];
	vis[x][y] = 1;

	for(int i = 0; i < 4; i++){
		int nx = x + (board[x][y] * dx[i]);
		int ny = y + (board[x][y] * dy[i]);
		dp[x][y] = max(dp[x][y], dfs(nx,ny)+1);
	}
	vis[x][y] = 0;
	return dp[x][y];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < m; j++){
			if(str[j] == 'H') board[i][j] = 0;
			else board[i][j] = str[j] - '0';
		}
	}
	int ans = 0;
	memset(dp,-1,sizeof(dp));
	ans = dfs(0,0);
	if(circle) cout << -1;
	else cout << ans;
} 
