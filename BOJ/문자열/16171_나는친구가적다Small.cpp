#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str, key;
	string cmp; 
	cin >> str;
	cin >> key;
	for(auto s : str){
		if(s < '0' || s > '9') //숫자아니면 
			cmp.push_back(s);
	}
	
	if(cmp.find(key)!= string::npos) cout << 1;
	else cout << 0;
}
