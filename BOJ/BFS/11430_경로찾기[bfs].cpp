#include <iostream>
#include <queue>
using namespace std;

int n;
int board[101][101];
int vis[101][101];
queue<pair<int,int>>q;

void bfs(int x, int y){
	
	vis[x][y] = 1;
	q.push({x,y});
	while(!q.empty()){
		for(int i = 0; i < n; i++){
			int idx = q.front().second;
			if(board[idx][i] and !vis[x][i]){
				vis[x][i] = 1;
				q.push({idx,i});
			}
		
		}q.pop();
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j])
				bfs(i,j);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << vis[i][j] << ' ';
		}
		cout << '\n';
	}
}
