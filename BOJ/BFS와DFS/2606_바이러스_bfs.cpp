#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num;
int n;
int visit[101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> num;
	cin >> n;
	
	vector<int> v[num+1];
	
	while(n--){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	int answer = 0;
	while(!q.empty()){
		int k = q.front(); q.pop();
		answer++;
		for(int j : v[k]){
			if(visit[j]) continue;
			visit[j] = 1;
			q.push(j);
		}
	}
	cout << answer - 1;
}
