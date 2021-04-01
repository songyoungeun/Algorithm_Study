#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	
	stack<char> s;
	int res = 0;
	
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			s.push('(');
		}
		else if( str[i] == ')' and str[i-1] == '('){//레이저일때  
			s.pop();
			res += s.size(); 
		}
		else{
			res++;
			s.pop();
		}
	}
	cout << res;
}
