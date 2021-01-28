#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	queue<int> Q;
	while(n--){
		string a;
		cin >> a;
		if (a == "push"){
			int num;
			cin >> num;
			Q.push(num);
		}
		else if(a == "pop"){
			if(Q.empty()) cout << -1 << '\n';
			else{
				cout << Q.front()<< '\n';
				Q.pop();
			}
		}
		else if(a == "size"){
			cout << Q.size()<< '\n';
		}
		else if(a == "empty"){
			if(Q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(a == "front"){
			if(Q.empty()) cout << -1 << '\n';
			else{
				cout << Q.front()<< '\n';
			}
		}		
		else{
			if(Q.empty()) cout << -1 << '\n';
			else{
				cout << Q.back()<< '\n';
			}
		}
	}

}
