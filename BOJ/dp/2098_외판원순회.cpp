#include <iostream>
#include <cstring>

using namespace std;
#define INF 987654321

int n, ans_bit;
int map[16][16];
int dp[16][1 << 16]; 

int dfs(int cur_node, int cur_bit){
	
	if(cur_bit == ans_bit){////다 돌고 처음 도시로 돌아가는 경우
		if(map[cur_node][0] == 0)return INF;
		else return map[cur_node][0];
	}	
	////앞으로 다 돌기까지 남은 길 중에 최솟값을 미리 구해놨다면, 그 경로가 최소임
	if(dp[cur_node][cur_bit] != -1) return dp[cur_node][cur_bit];
	dp[cur_node][cur_bit] = INF;
	
	for(int i = 0; i < n; i++){
		////1. 길이 없거나, 2. 한번방문한 도시(i)를 다시 방문하려고 한다면 --> 건너뛰어야함
		if(map[cur_node][i] == 0)continue;
		if((cur_bit & (1 << i)) == (1 << i)) continue;
		dp[cur_node][cur_bit] = min(dp[cur_node][cur_bit], map[cur_node][i] + dfs(i, cur_bit | 1 << i));
	}
	return dp[cur_node][cur_bit];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	ans_bit = (1 << n) -1;
	memset(dp,-1,sizeof(dp));
	cout << dfs(0,1);
} 
