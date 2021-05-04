#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int dp[501];
int time[501];
int indegree[501];
vector<int>v[501];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int prev;
	for(int i = 1; i <= n; i++){
		cin >> time[i];
		while(1){
			int prev;
			cin >> prev;
			if(prev == -1) break;
			indegree[i]++;
			v[prev].push_back(i);
		}
		
	}
	queue<int>q;
	for(int i = 1; i <= n; i++){
		if(!indegree[i]){
			q.push(i);
			dp[i] = time[i];
		}
	}
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int i = 0; i < v[cur].size(); i++){
			int next = v[cur][i];
			indegree[next]--;
		 	dp[next] = max(dp[next], dp[cur] + time[next]);
			if(indegree[next] == 0)
				q.push(next);
		}
	}
	for(int i = 1; i <= n; i++)
		cout << dp[i]<<'\n';
	
}
