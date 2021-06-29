#include <iostream>

using namespace std;

bool chkpalin(string str){
	int s = 0;
	int e = str.length() -1;
	while(s < e){
		if(str[s] != str[e]){
			return 0;
		}
		else{
			s++;
			e--;
		}
	}
	return 1;
}

void canpalin(string str){
	int s = 0;
	int e = str.length() -1;
	while(s < e){
		if(str[s] != str[e]){
			string original = str;
			string tmp1 = str.erase(s,1);
			string tmp2 = original.erase(e,1);
			if(chkpalin(tmp1)){
				cout << 1 << '\n';
			}
			else if(chkpalin(tmp2)){
				cout << 1 << '\n';
			}
			else{
				cout << 2 << '\n';
			}
			return;
		}
		else{
			s++;
			e--;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		if(chkpalin(str)){
			cout << 0 <<'\n';
		}
		else{
			canpalin(str);
		}
	}
	return 0;
} 
