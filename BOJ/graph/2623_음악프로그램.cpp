#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n ,m;
int indeg[1002];
vector<int> con[1002];

void input(){

	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int cnt, x, y;
		cin >> cnt;
		cin >> x;
		for(int j = 2; j <= cnt; j++){
			cin >> y;
			con[x].push_back(y);
			indeg[y]++;
			x = y;
		}
	}
}

#include <queue>
void pro(){
	queue<int>q;
	
	for(int i = 1; i <= n; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	vector<int> ans;
	//우선순위에 대한 조건을 간선으로 표현했으므로 위상정렬 수행하면 됨
	 
	while(!q.empty()){
		int x = q.front();
		ans.push_back(x);
		q.pop();
		for(int y : con[x]){
			indeg[y]--;
			if(indeg[y] == 0) q.push(y);
		}
	}
	if(ans.size() != n) cout << 0;
	else for(int x : ans) cout << x << '\n';
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	
	return 0;
}
