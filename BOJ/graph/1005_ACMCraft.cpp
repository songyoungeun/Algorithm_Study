#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n ,k, w;
int indeg[1002], t[1002], t_done[1002];
vector<int> con[1002];

void input(){

	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		t_done[i] = 0;
		indeg[i] = 0;
		con[i].clear();
	}
	for(int i = 1; i <= k; i++){
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		indeg[y]++;
	}
}

#include <queue>
void pro(){
	queue<int>q;
	
	for(int i = 1; i <= n; i++){
		if(indeg[i] == 0){
			q.push(i);
			t_done[i] = t[i];
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int y : con[x]){
			indeg[y]--;
			if(indeg[y] == 0) q.push(y);
			t_done[y] = max(t_done[y], t_done[x] + t[y]);
		}
	}
	cin >> w;
	cout << t_done[w] << '\n';
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
		pro();
	}
	return 0;
}
