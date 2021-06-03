#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define x first
#define y second
int t, l;
int startx,starty,destx,desty;
int dist[300][300];
int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};

void bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		
		if(cur.x == destx && cur.y == desty){
			
			cout << dist[cur.x][cur.y] <<'\n';
			return;		
		} 
		
		for(int idx = 0; idx < 8; idx++){
			int nx = cur.x + dx[idx];
			int ny = cur.y + dy[idx];
			if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
			if(dist[nx][ny]) continue;
			dist[nx][ny] = dist[cur.x][cur.y]+1;
			q.push({nx,ny});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> l;
		cin >> startx >> starty >> destx >> desty;
		bfs(startx,starty);
		memset(dist,0,sizeof(dist));	
	}
}

