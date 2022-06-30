#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, indeg[32001];
vector<int> con[32001];

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
		indeg[b]++;
	}	
}
#include <queue>
void pro(){
	queue<int> Q;
	for(int i = 1; i <= n; i++){
		if(indeg[i] == 0) Q.push(i);
	}
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		cout << x << ' ';
		for(int y : con[x]){
			indeg[y]--;
			if(indeg[y] == 0)
				Q.push(y);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
