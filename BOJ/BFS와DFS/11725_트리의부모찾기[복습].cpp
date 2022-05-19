#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> node[100005];
int parent[100005];

void input(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
}

void dfs(int x, int par){
	for(int y : node[x]){
		if(y == par) continue;
		parent[y] = x;
		dfs(y, x);
	}
}


void pro(){
	dfs(1,-1);
	for(int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
}
