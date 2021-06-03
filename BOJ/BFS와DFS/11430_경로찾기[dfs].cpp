#include <iostream>
#include <cstring>
using namespace std;

int n;
int board[101][101];
bool vis[101];

void dfs(int idx){
	for(int i = 0; i < n; i++){
		if(board[idx][i] == 1 and !vis[i]){
			vis[i] = 1;
			dfs(i);
		}
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
		memset(vis,0,sizeof(vis));
		dfs(i);
		for(int j = 0; j < n; j++){
			if(vis[j])
				board[i][j] = 1;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
