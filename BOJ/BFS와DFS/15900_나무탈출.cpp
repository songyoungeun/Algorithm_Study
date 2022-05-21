#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> con[500001];

void input(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
}

int leaf = 0; //모든 leaf node 들의 깊이의 합  
void dfs(int x, int pra, int depth){
	if(x != 1 && con[x].size() == 1) leaf += depth;
	for(int y : con[x]){
		if(y == pra) continue;
		dfs(y,x,depth + 1);
	}
}

void pro(){
	dfs(1,-1,0);
	
	if(leaf % 2 == 0) cout << "No";
	else cout << "Yes";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
}
