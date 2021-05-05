#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int V, E;
	cin >> V >> E;
	int start;
	cin >> start;
	vector<pair<int,int>> graph[V+1];
	for(int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v,w});
	}
	int dist[V+1];
	fill(dist,dist+V+1,INF);
	priority_queue<pair<int,int>> q;
	
	q.push({0,start});
	dist[start] = 0;
	
	while(!q.empty()){
		int cost=-q.top().first;    // cost는 다음 방문할 점의 dist값을 뜻합니다. 
        int here=q.top().second;     // here을 방문할 점의 번호를 뜻합니다 
        q.pop();
		for(int i = 0; i < graph[here].size(); i++){
			int next = graph[here][i].first;
			int nxcost = graph[here][i].second;
			if(dist[next] > dist[here] + nxcost){
				//현재 next에 저장된 dist의 값보다 현재의 점을 거쳐 갈 경우
				//거리가 짧으면 갱신 -> 큐넣기 
				dist[next] = dist[here] + nxcost;
				q.push({-dist[next],next}); 
			}
		} 
	}
	for(int i = 1; i <= V; i++){
		if(dist[i] == INF){
			cout << "INF" <<'\n';	
		}
		else{
			cout << dist[i] <<'\n';
		}
	
	}
	
}
