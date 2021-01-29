#include <iostream>
#include <queue>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	queue<int> q;
	for(int i = 1; i < n+1; i++){
		q.push(i);	
	}
	int a;
	while(q.size() != 1){
		q.pop();
		a = q.front();
		q.pop();
		q.push(a);
	}
	cout << q.front();
}
