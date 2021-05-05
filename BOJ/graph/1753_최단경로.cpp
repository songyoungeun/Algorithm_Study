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
		int cost=-q.top().first;    // cost�� ���� �湮�� ���� dist���� ���մϴ�. 
        int here=q.top().second;     // here�� �湮�� ���� ��ȣ�� ���մϴ� 
        q.pop();
		for(int i = 0; i < graph[here].size(); i++){
			int next = graph[here][i].first;
			int nxcost = graph[here][i].second;
			if(dist[next] > dist[here] + nxcost){
				//���� next�� ����� dist�� ������ ������ ���� ���� �� ���
				//�Ÿ��� ª���� ���� -> ť�ֱ� 
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
