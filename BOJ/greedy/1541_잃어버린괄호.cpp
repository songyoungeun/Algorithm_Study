#include <iostream>
#include <string>

using namespace std;

string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	string tmp = "";
	int res = 0;
	int minus = 0;
	for(int i = 0; i <= s.length(); i++){
		if(s[i] == '+' || s[i] == '-' || s[i] == NULL){
			if(minus == 1)
				res -= stoi(tmp);
			else
				res += stoi(tmp);
			tmp = "";
			if(s[i] == '-')
				minus = 1;
		}	
		else{
			tmp += s[i];
		}
	}
	cout << res;
}
