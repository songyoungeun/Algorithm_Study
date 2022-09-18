#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> g(105);
bool vis[105];
int n, m;

void dfs(int cur){
	vis[cur] = 1;
	for(const int &nxt : g[cur]){
		if(!vis[nxt]) dfs(nxt);
	}	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += vis[i];
	cout << ans - 1;
	return 0;
}
