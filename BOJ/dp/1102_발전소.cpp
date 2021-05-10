#include <iostream>
#include <cstring>

using namespace std;
#define INF 987654321

int n, p;
int ans = INF;
string str;
int map[16][16];
int dp[1 << 16];

int count(int b){
	//비트 내 1 세는 법  
	int cnt = 0;
	while(b != 0){
		cnt += (b & 1);
		b >>= 1;
	}
	cout << "2: "<<cnt <<'\n';
	return cnt;
}
int dfs(int state){
	cout << "state: " << state <<'\n';
	if(count(state) >= p) return 0;
	if(dp[state] != -1)	return dp[state];
	dp[state] = INF;
	for(int i = 0; i < n; i++){
		if((state & (1 << i)) == 0) continue;
		for(int j = 0; j < n; j++){
			if((state & (1 << j)) == 0){
				int next = state | (1 << j);
				cout << "3: " << next <<'\n';
				dp[state] = min(dp[state], map[i][j] + dfs(next));
			}
		}
	}
	return dp[state];
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
	cin >> str;
	cin >> p;
	int bitstate = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'Y')
			bitstate |= (1 << i);
			cout << "0: " << bitstate <<'\n';
	}
	cout << "1: "<< bitstate <<'\n';
	memset(dp,-1,sizeof(dp));
	ans = dfs(bitstate);
	if(ans == INF) cout << -1;
	else cout << ans;
} 
