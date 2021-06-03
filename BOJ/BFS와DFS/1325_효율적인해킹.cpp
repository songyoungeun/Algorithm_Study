#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
vector<int>board[10001];
bool vis[10001];
int cnt;

void dfs(int node){
	vis[node] = 1;
	for(int i = 0; i < board[node].size(); i++){
		int nxt = board[node][i];
		if(!vis[nxt]){
			cnt++;
			dfs(nxt);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int a, b; 
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		board[b].push_back(a);
	}	
	int maxhacking = 0;
	vector<int> result;
	for(int i = 1; i <= n; i++){
		memset(vis,0,sizeof(vis));
		cnt = 0;
		dfs(i);
		if(maxhacking == cnt){
			result.push_back(i);
		}
		if(maxhacking < cnt){
			maxhacking = cnt;
			result.clear();
			result.push_back(i);
		}
	}
	sort(result.begin(),result.end());
	for(int i = 0; i < result.size(); i++){
		cout << result[i]<< ' ';
	}
}
