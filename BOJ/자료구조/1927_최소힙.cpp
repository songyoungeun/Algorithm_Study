#include <iostream>
#include <queue>

using namespace std;

int n, num;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while(n--){
		cin >> num;
		if(num == 0){
			if(!pq.empty()){
				cout << pq.top() << '\n';
				pq.pop();
			}
			else{
				cout << 0 << '\n';				
			}
		}
		else{
			pq.push(num);
		}
	}
}
