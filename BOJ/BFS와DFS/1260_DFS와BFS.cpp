#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
vector<vector<int>> g(1002);
bool vis[1002];
int n, m, v;
void dfs(int cur){
	vis[cur] = 1;
	cout << cur <<' ';
	for(int k : g[cur]){
		if(!vis[k])dfs(k);
	}
}
void bfs(int cur){
	queue<int> q;
	q.push(cur);
	vis[cur] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		cout << x << ' ';
		for(int k : g[x]){
			if(!vis[k]){
				q.push(k);
				vis[k] = 1;
			} 
		}
	}

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> v;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	// 번호가 더 빠른 정점을 방문하기 위해서 인접 리스트를 정점 번호순으로 정렬
    for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
	dfs(v);
	memset(vis, false, sizeof(vis));
	cout << '\n';
	bfs(v);
	
}
