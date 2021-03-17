#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define x first
#define y second
int n, k;
int dist[2][500001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fill(dist[0],dist[0]+500001,-1);
	fill(dist[1],dist[1]+500001,-1);
	dist[0][n] = 0;
	queue<pair<int,int>> q;
	q.push({0,n});

	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(auto nxt:{cur.y-1, cur.y+1, 2*cur.y}){
			if(nxt < 0 || nxt > 500000) continue;
			if(dist[1-cur.x][nxt] != -1) continue;
			dist[1-cur.x][nxt] = dist[cur.x][cur.y]+1;
			q.push({1-cur.x,nxt});
		}
	}
	int ans = 0x7f7f7f7;
	int tt = 0;
	while(k <= 500000){
		if(dist[tt%2][k] != -1 and dist[tt%2][k] <= tt) ans = min(ans,tt);
		tt++;
		k += tt;
	}
	if(ans == 0x7f7f7f7) ans = -1;
	
	cout << ans;
	return 0;
	
}
