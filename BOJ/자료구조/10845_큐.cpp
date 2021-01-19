#include <iostream>
#include <queue> 
#include <string> 
using namespace std;
int main(void) {
	int n;
	cin>> n;
	queue<int> q;
	while(n--){
		string s;
		cin >> s;
		if(s=="push"){
			int a;
			cin >> a;
			q.push(a);	
		} 
		else if(s == "pop"){
			if(q.empty()) cout<< -1 << '\n';
			else{
				cout<< q.front();
				q.pop();
			}
		}
		else if(s == "size"){
			cout<< q.size();
		}
		else if(s == "empty"){
			cout << q.empty();
		}
		else if(s=="front"){
			if(q.empty()) cout<< -1 << '\n';
			else{
				cout<< q.front();
			}
		}
		else{
			if(q.empty()) cout<< -1 << '\n';
			else{
				cout<< q.back();
			}
		}
	}
}
