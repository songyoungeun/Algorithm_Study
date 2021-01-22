#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int dist[100002];
int n,m;
100002
100002
100001
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n >> m;
	fill(dist,dist+100001,-1);
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while(dist[m] == -1){
		int cur = q.front(); q.pop();
		for(int c:{cur-1, cur+1, 2*cur}){
			if(c < 0 || c > 100000) continue;
			if(dist[c] != -1) continue;
			dist[c] = dist[cur] +1;
			q.push(c);
		}
	}
	cout << dist[m];

	
}
