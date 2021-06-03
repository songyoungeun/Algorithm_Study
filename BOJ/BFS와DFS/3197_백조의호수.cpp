#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define x first
#define y second

int r,c,x,y;
string str;

char lake[1501][1501];
bool vis[1501][1501];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	queue<pair<int,int>>water;
	
	for(int i = 0; i < r; i++){
		cin >> str;
		for(int j = 0; j < c; j++){
			lake[i][j] = str[j];
			if(lake[i][j] == 'L'){
				x = i;
				y = j; //l의 위 
			}
			if(lake[i][j] == '.' or lake[i][j] == 'L'){
				water.push({i,j});
			}
		}
	}
	queue<pair<int,int>>q;
	q.push({x,y});
	vis[x][y] = 1;
	int time = 0;
	while(1){
		queue<pair<int,int>>nxt;
		bool suc = false;
		while(!q.empty() and !suc){
			auto cur = q.front(); q.pop();
			for(int idx = 0; idx < 4; idx++){
				int nx = cur.x + dx[idx];
				int ny = cur.y + dy[idx];
				if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if(lake[nx][ny] == 'L' && vis[nx][ny] == 0){
					suc = true;
					break;
				}//다른 백조 만나면 성공임
				if(lake[nx][ny] == '.' && vis[nx][ny] == 0){
					q.push({nx,ny});
					vis[nx][ny] = 1;
				}//물인데 방문한적없으면 큐에 넣는다
				if(lake[nx][ny] == 'X' && vis[nx][ny] == 0){
					nxt.push({nx,ny});
					vis[nx][ny] = 1;
				} //물 옆에 있는 얼음이면 다음에 방문할 것임 
			}
		}
		if(suc){
			cout << time <<'\n';
			break;
		} 
		q = nxt;
		int watersize = water.size();
		while(watersize--){
			auto cur = water.front(); water.pop();
			for(int idx = 0; idx < 4; idx++){
				int nx = cur.x + dx[idx];
				int ny = cur.y + dy[idx];
				if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if(lake[nx][ny] == 'X'){
					water.push({nx,ny});
					lake[nx][ny] = '.';
				}
			}
		} 
		time++;
	}
	return 0;
} 
