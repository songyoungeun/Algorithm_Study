#include <iostream>
#include <stack> 
#include <string> 
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int n;
	cin>> n;
	while(n--){
		string c;
		cin >> c;
		if(c == "push"){
			int a;
			cin>>a;
			s.push(a);
		} 
		else if(c == "top"){
			if(s.empty()) cout<< -1<<'\n';
			else cout<< s.top()<< '\n';
		}
		else if(c == "pop"){
			if(s.empty()) cout<< -1<<'\n';
			else{
				cout<< s.top() <<'\n';
				s.pop()
;			} 
			
		}
		else if(c == "size"){
			cout << s.size()<<'\n';
		}
		else{
			cout << (int)s.empty() << '\n';
		}
	}
}
