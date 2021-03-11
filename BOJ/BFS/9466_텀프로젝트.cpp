#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int t, n;
int student[100005];
bool vis[100005];

int bfs(int start, vector<int>& circuit){
	queue<int> q;
	q.push(start);
	vis[start] = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		circuit.push_back(cur);
		int num = student[cur];
		if(!vis[num]){
			vis[num] = 1;
			q.push(num);
		}
		else 
			return num;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		memset(vis, false, sizeof(vis));
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> student[i];
		}
		int result = 0;
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				vector<int> circuit;
				int idx = bfs(i,circuit);
				int len = circuit.size();
				for(int i = 0; i < len; i++){
					if(idx == circuit[i]) break;
					result ++;
				}
				
			}
		}cout << result << '\n';
		
	}
	return 0;
}
