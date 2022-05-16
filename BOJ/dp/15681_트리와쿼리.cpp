#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define NM 100005

int n, r, q;
int dy[NM];
vector<int> con[NM];

void input(){
	cin >> n >> r >> q;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
}

void dfs(int x, int prev){
	dy[x] = 1;
	for(int y : con[x]){
		if(y == prev) continue;
		dfs(y, x);
		dy[x] += dy[y];
	}
}

void pro(){
	dfs(r, -1);
	while(q--){
		int x; 
		cin >> x;
		cout << dy[x] << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
