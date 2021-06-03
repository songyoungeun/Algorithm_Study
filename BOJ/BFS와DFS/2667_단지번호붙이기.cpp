#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n;
string map[25];
int vis[25][25];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> house;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> map[i];		
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j] == '0' || vis[i][j]) continue;
			cnt++;
			queue<pair<int,int>> q;
			vis[i][j] = 1;
			q.push({i,j});
			int area = 0;
			while(!q.empty()){
				area++;
				pair<int,int> cur = q.front(); q.pop();
				for(int idx = 0; idx < 4; idx++){
					int nx = cur.X + dx[idx];
					int ny = cur.Y + dy[idx];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(vis[nx][ny] || map[nx][ny] == '0') continue;
					vis[nx][ny] = 1;
					q.push({nx,ny});
				}
					
			}
			house.push_back(area);
		}
	}

	sort(house.begin(), house.end());
	cout << cnt << '\n';
	for(int i = 0; i < cnt; i++) 
		cout << house[i] << '\n';
}
