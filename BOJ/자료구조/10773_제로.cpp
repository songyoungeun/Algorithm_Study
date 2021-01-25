#include <iostream>
#include <stack>
using namespace std;

int main(){
	int k, n;
	int sum = 0;
	cin >> k;
	stack<int> S;
	for(int i = 0; i < k; i++){
		cin >> n;
		if(n != 0){
			S.push(n);
		}
		else S.pop();
	}
	while(!S.empty()){
		sum += S.top();
		S.pop();
	}
	cout << sum;
}
