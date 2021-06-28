#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
bool vis[100001];
int parent[100001];
vector<int> tree[100001];

//void d_findparent(int nodenum){
//	vis[nodenum] = 1;
//	for(int i = 0; i < tree[nodenum].size(); i++){
//		int nxt = tree[nodenum][i];
//		if(!vis[nxt]){
//			parent[nxt] = nodenum; // nxtÀÇ parent´Â nodenum 
//			d_findparent(nxt);
//		}
//	}
//}
void b_findparent(){
	queue<int> q;
	q.push(1);

	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(auto nxt : tree[cur]){
			if(parent[cur] == nxt) continue;
			q.push(nxt);
			parent[nxt] = cur;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int node1, node2;
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
//	d_findparent(1); //dfs
	b_findparent(); //bfs
	for(int i = 2; i <= n; i++){
		cout << parent[i] << '\n';
	}
	return 0;
	
} 
