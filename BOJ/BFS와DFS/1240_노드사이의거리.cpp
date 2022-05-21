#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int,int>> con[1005];
int ans = 0;

void input(){
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int u, v, c;
		cin >> u >> v >> c; 
		con[u].push_back({v,c});
		con[v].push_back({u,c});
	}
}
void dfs(int x, int prev, int goal, int dist){
	if(x == goal){
		ans = dist;
		return;
	}
	for(auto& p : con[x]){
		auto[y, c] = p;
		if(y == prev) continue;
		dfs(y, x, goal, dist + c);
	}
}
void pro(){
	int x, y;
	cin >> x >> y;
	dfs(x,-1,y,0);
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	while(m--){
		pro();
	}
}
