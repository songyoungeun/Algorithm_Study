#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	//��� ���� �� ������ �޸� �ʰ�
	//pq���� ���̸� ã��  
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
