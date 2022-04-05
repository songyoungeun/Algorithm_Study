#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
char a[300][300];

void input(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
		
}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, totalsheep, totalwolf;
bool vis[300][300];
int sheep, wolf;
//x,y를 갈 수 있다는 걸 알고 방문한 상태
void dfs(int x, int y){
	if(a[x][y] == 'o') sheep++;
	if(a[x][y] == 'v') wolf++;
	vis[x][y] = true;
	for(int k = 0; k < 4; k++){
		int nx = x + dir[k][0];
		int ny = y + dir[k][1];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if(a[nx][ny] == '#') continue;
		if(vis[nx][ny]) continue;
		dfs(nx,ny);
	}
}
void pro(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] != '#' && !vis[i][j]){
				sheep = wolf = 0;
				dfs(i,j);
				if(sheep > wolf) totalsheep += sheep; //영역안에 늑대 수보다 많으면 이김  
				else totalwolf += wolf;
            }
	cout << totalsheep << " " << totalwolf;
			
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
