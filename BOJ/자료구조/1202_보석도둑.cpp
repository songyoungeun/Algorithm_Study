#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int bag[300001];
pair<int,int> jew[300001];
priority_queue<int> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> jew[i].first >> jew[i].second;
	for(int i = 0; i < k; i++)
		cin >> bag[i];
	sort(jew,jew+n);
	sort(bag,bag+k);
	
	long long ans = 0;
	int idx = 0;
	for(int i = 0; i < k; i++){
		while(idx < n and jew[idx].first <= bag[i]){
			pq.push(jew[idx++].second);
		}
		if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
		
	}
	cout << ans;
}
