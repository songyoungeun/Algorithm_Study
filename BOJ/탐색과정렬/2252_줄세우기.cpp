#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b;
int indegree[32001];
vector<int>graph[32001];

void TopologicalSort(){
	queue<int>q;
	//inDegree가 0이라는 것은 순위가 제일 높을 수 있다는 뜻이므로 큐에 미리 넣기  
	for(int i = 1; i <= n; i++){
		if(!indegree[i])
			q.push(i);
	}
	while(!q.empty()){
		int cur = q.front(); q.pop();
		cout << cur <<' ';
		for(int i = 0; i < graph[cur].size(); i++){
			indegree[graph[cur][i]]--;
			if(!indegree[graph[cur][i]])
				q.push(graph[cur][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	TopologicalSort();
}
