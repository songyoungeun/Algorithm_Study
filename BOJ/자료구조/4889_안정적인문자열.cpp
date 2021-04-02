#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string input;
stack<char> s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	

	int ord = 1;
	while(1){
		cin >> input;
		int ans = 0;
		for(int i = 0; i < input.length(); i++){
			if(input[i] == '{'){
				s.push('{');
			}
			else if(input[i] == '}'){
				if(s.empty() or s.top() != '{'){
					s.push('}');
				}
				else
					s.pop();
			}
			else{
				return 0;
			}
		}
		while(!s.empty()){
			char a = s.top();
			s.pop();
			if(a != s.top()){
				ans += 2;
			}
			else{
				ans += 1;
			}
			s.pop();

		}
		cout << ord++ <<". "<< ans <<'\n';
	}
	
	
} 
