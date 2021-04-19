#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
bool vis[200001];
queue<pair<int,int>>q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	
	q.push({n,0});

	while(!q.empty()){
		int now = q.front().first;
		int time = q.front().second;
		vis[now] = 1;
		q.pop();
		if(now == k){ //µµÂø  
			cout << time;
			break;
		}
		int a = 2 * now;
		if(a >= 0 and a <= 200000 and !vis[a]){
			q.push({a,time});
			vis[a] = 1;  
		}
		int b = now - 1;
		if(b >= 0 and b <= 200000 and !vis[b]){
			q.push({b,time+1});
			vis[b] = 1;  
		}
		int c = now + 1;
		if(c >= 0 and c <= 200000 and !vis[c]){
			q.push({c,time+1});
			vis[c] = 1;  
		}
	}
}
