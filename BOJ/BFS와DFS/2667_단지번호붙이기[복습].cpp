#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 30

int N;
char a[NM][NM];

void input(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> a[i][j];
		}
	}
}

#include <queue>
queue<int> Q;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, group_cnt;
bool visit[NM][NM];

//x,y를 갈 수 있다는 걸 알고 방문한 상태
void dfs(int x, int y){
	//단지에 속한 집의 개수 증가, visit체크 하기
	group_cnt++;
	visit[x][y] = true;
	//인접한 집으로 새로운 방문하기
	for(int k = 0; k < 4; k++){
		int nx = x + dir[k][0];
		int ny = y + dir[k][1];
		if(nx < 1 || ny < 1 || nx > N || ny > N) continue;//지도 벗어나는 곳인가?
		if(a[nx][ny] == '0') continue; //갈수있는 칸인가?
		if(visit[nx][ny]) continue;
		dfs(nx,ny);
		
	}
	
}
void pro(){
	vector<int> groups;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(a[i][j] == '1' && !visit[i][j]){
				//갈수 있는 칸, 즉 새롭게 만난 단지인 경우!
				group_cnt = 0;
				dfs(i, j);
				groups.push_back(group_cnt);
				 
			}
		}
	}
	//찾은 단지의 정보를 출력하기
	sort(groups.begin(), groups.end());
	cout << groups.size() << '\n';
	for(int g : groups) cout << g << '\n';	 
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input(); 
	pro();

	
} 
