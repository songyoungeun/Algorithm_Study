#include <iostream>
#include <algorithm>
using namespace std;

#define NM 11
int N, M, b, a[NM][NM], blank[NM * NM][2], ans;
bool visit[NM][NM];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void input(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> a[i][j];
		}
	}
}
#include <queue>
void bfs(){
	queue<int> Q;
	//모든 바이러스가 시작점으로 가능하니까, 전부 큐에 넣어준다.
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			visit[i][j] = false;
			if(a[i][j] == 2){
				Q.push(i);
				Q.push(j);
				visit[i][j] = true;
			}
		}
	}
	//bfs과정
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		int y = Q.front(); Q.pop();
		for(int k = 0; k < 4; k++){
			int nx = x + dir[k][0] , ny = y + dir[k][1];
			if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if(a[nx][ny] != 0) continue;
			if(visit[nx][ny]) continue;
			visit[nx][ny] = true;
			Q.push(nx);
			Q.push(ny);
		}
	} 
	//탐색이 종료된 시점이니, 안전 영역의 넓이를 계산하고 정답을 갱신한다.
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(a[i][j] == 0 && !visit[i][j])
				cnt++;
		}
	}
	ans = max(ans, cnt);	 
}
void dfs(int idx, int selected_cnt){
	if(selected_cnt == 3){
		bfs();
		return;
	}
	if(idx > b) return;
	
	a[blank[idx][0]][blank[idx][1]] = 1;
	dfs(idx + 1, selected_cnt + 1);
	
	a[blank[idx][0]][blank[idx][1]] = 0;
	dfs(idx + 1, selected_cnt);
}
void pro(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(a[i][j] == 0){
				b++;
				blank[b][0] = i;
				blank[b][1] = j;
			}
		}
	}
	dfs(1,0);

	cout << ans;

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
