#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		string str;
		stack<char> ss;
		getline(cin, str);
		if(str == ".") break;
		bool isbalance = true;
		for(auto k : str){
			if(k == '(' || k == '['){
				ss.push(k);
			}
			else if(k == ')'){
				if(ss.empty() || ss.top() != '('){
					isbalance = false;
					break;
				}
				ss.pop();
			}
			else if(k == ']'){
				if(ss.empty() || ss.top() != '['){
					isbalance = false;
					break;
				}
				ss.pop();
			}
		
		}

		if(!ss.empty()) isbalance = false;
		if(isbalance) cout << "yes" <<'\n';
		else cout << "no" <<'\n';

		
	}
}
