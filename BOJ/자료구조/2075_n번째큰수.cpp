#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	//모든 수를 다 넣으면 메모리 초과
	//pq수를 줄이며 찾기  
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int num;
			cin >> num;
			pq.push(num);
			if(pq.size() > n){
				pq.pop();
			} 
		}
	}

	cout << pq.top();

}
