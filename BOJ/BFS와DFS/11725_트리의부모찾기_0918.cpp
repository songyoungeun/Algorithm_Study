#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<vector<int>> g(100002);
//bool vis[100002];
int ans[100002]; //parent

void dfs(int cur){
//	vis[cur] = 1;

	for(int k : g[cur]){
		if(ans[cur] == k) continue; // parent[cur] == nxt
		ans[k] = cur; //parent[nxt] = cur;
		dfs(k); //dfs(nxt);
//		if(!vis[k])dfs(k);
//		else{
//			ans[cur] = k;
//		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);
	for(int i = 2; i <= n; i++){
		cout << ans[i] <<'\n';
	}
}
