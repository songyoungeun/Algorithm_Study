#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int k, n, p;
vector<int> con[32005];
int indeg[32005], order[32005], maxCnt[32005];

void input(){

	cin >> k >> n >> p;
	for(int i = 1; i <= n; i++){
		indeg[i] = order[i] = 0;
		con[i].clear();
	}
	for(int i = 1; i <= p; i++){
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		indeg[y]++;
	}
}
#include <queue>
void pro(){
	queue<int> q;
	//제일 앞에 정렬될 수 있는 정점 찾기
	for(int i = 1; i <= n; i++){
		if(indeg[i] == 0){
			q.push(i);
			order[i] = 1;
			maxCnt[i] = 1;
		}
	} 
	int ans = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(maxCnt[x] >= 2) order[x]++;
		ans = max(ans, order[x]);
		for(int y : con[x]){
			indeg[y]--;
			if(indeg[y] == 0) q.push(y);
			if(order[y] == order[x]) maxCnt[y]++;
			else if(order[y] < order[x]){
				order[y] = order[x];
				maxCnt[y] = 1;
			}
		}
	}
	cout << k << " " << ans <<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		input();
		pro();
	}
}
