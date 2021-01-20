#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(true){
		string s;
		getline(cin, s); 
		if(s == ".") break;
		stack<char> S;
		bool isVaild = true;
		for(auto c:s){
			if(c == '(' || c == '[') S.push(c);
			else if(c == ')'){
				if(S.empty() || S.top() != '('){
					isVaild = false;
					break;	
				}
				S.pop();					
			}
			else if(c== ']'){
				if(S.empty() || S.top() != '['){
					isVaild = false;
					break;	
				}
				S.pop() ;
			}
		}
		if(!S.empty()) isVaild = false;
		if(isVaild) cout << "yes\n";
		else cout << "no\n";	
	}
}
