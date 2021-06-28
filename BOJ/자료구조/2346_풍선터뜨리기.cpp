#include <iostream>
#include <deque>
using namespace std;

int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	deque<pair<int,int>> dq;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a; 
		dq.push_back({i+1,a});
	}
	int val = dq.front().second;
	cout << dq.front().first <<' ';
	dq.pop_front();
	
	while(!dq.empty()){
		if(val > 0){
			for(int i = 0; i < val; i++){
				dq.push_back({dq.front().first,dq.front().second});
				dq.pop_front();
			}
			val = dq.back().second;
			cout << dq.back().first << ' ';
			dq.pop_back();
		}
		else{
			for(int i = 0; i < abs(val); i++){
				dq.push_front({dq.back().first,dq.back().second});
				dq.pop_back();
			}
			val = dq.front().second;
			cout << dq.front().first <<' ';
			dq.pop_front();
			
		}
	}
}
