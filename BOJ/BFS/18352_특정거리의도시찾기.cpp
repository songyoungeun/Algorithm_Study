#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x, a, b;
vector<int> map[300001];
int dist[300001];

void bfs(int x){
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		
		for(int i = 0; i < map[cur].size(); i++){
			int idx = map[cur][i];
			if(!dist[idx] and idx != x){
				dist[idx] = dist[cur] +1;
				q.push(idx);
			}
		}
	}	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k >> x;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		map[a].push_back(b);
	}
	bfs(x);
	vector<int> ans;
	for(int i = 1; i <= n; i++){
		if(dist[i] == k) ans.push_back(i);
	}
	if(ans.size() == 0) cout << -1 << '\n';
	else{
		sort(ans.begin(),ans.end());
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << '\n';
		}
	}
}
