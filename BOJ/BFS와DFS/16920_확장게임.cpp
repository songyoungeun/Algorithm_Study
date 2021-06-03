#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
#define x first
#define y second

int n, m, p;
long long s[10];
int board[1001][1001];
int res[10];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>>q[10];

void bfs(int now){
	for(int i = 0; i < s[now]; i++){
		int q_size = q[now].size();
		if(q_size == 0) return;
		while(q_size--){
			auto cur = q[now].front(); q[now].pop();
			for(int idx = 0; idx < 4; idx++){
				int nx = cur.x + dx[idx];
				int ny = cur.y + dy[idx];
				if(nx < 0|| nx >= n|| ny < 0 || ny >= m) continue;
				if(board[nx][ny] != 0) continue;
				q[now].push({nx,ny});
				board[nx][ny] = now;
				res[now]++;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	for(int i = 1; i <= p; i++) cin >> s[i];
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < m; j++){
			if(isdigit(str[j])){
				board[i][j] = str[j] - '0';
				q[board[i][j]].push({i,j});
				res[board[i][j]]++;
			}
			else if(str[j] == '#'){
				board[i][j] = -1;
			}
		}
	}
	while(1){
		int ck = 0;
		for(int i = 1; i <= p; i++){
			if(q[i].empty()){
				ck++;
			}
			else bfs(i);
		}
		if(ck == p) break;
	}
	for(int i = 1; i <= p; i++){
		cout << res[i] <<' ';	
	}
}

	
