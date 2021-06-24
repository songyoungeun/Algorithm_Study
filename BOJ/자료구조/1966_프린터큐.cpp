#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test;
	cin >> test;
	for(int i = 0; i < test; i++){
		int n, m, cnt = 0;
		queue<pair<int,int>> q;
		priority_queue <int> pq;
		
		cin >> n >> m;
		for(int j = 0; j < n; j++){
			int a;
			cin >> a;
			q.push({j,a});
			pq.push(a);
		}
		while(!q.empty()){
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if(pq.top() == val){
				pq.pop();
				cnt++;
				if(idx == m){
					cout << cnt <<'\n';
					break;
				}
			}
			else{
				q.push({idx,val});
			}
		}
	}
	
	return 0;
}
