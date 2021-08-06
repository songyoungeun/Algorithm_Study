#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define x first
#define y second

int n, m;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dist[101][101];
string board[101];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> board[i];
	}
	for(int i = 0; i < n; i++) fill(dist[i],dist[i] + m, -1);
	
	queue<pair<int,int>> q;
	q.push({0,0});
	dist[0][0] = 1;
	while(!q.empty()){
		pair<int,int> cur = q.front(); q.pop();
		for(int idx = 0; idx < 4; idx++){
			int nx = cur.x + dx[idx];
			int ny = cur.y + dy[idx];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(board[nx][ny] != '1' || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			q.push({nx,ny});
		}
	}
	cout << dist[n-1][m-1];
} 
