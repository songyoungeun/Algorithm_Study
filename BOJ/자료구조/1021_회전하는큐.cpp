#include <iostream>
#include <deque>

using namespace std;

int n, m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	deque<int> dq;
	for(int i = 1; i <= n; i++){
		dq.push_back(i);
	}
	int cnt = 0;
	while(m--){
		int num, idx;
		cin >> num;
		for(int i = 0; i < dq.size(); i++){
			if(dq[i] == num){
				idx = i;
				break;
			}
		}
		if(idx < dq.size() - idx){
			while(1){
				if(dq.front() == num){
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else{
			while(1){
				if(dq.front() == num){
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	cout << cnt;
} 
