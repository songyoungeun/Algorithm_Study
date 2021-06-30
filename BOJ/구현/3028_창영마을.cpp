#include <iostream>
//#include <algorithm>
using namespace std;

int cup[3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cup[0] = 1;
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'A'){
			int tmp;
			tmp = cup[0];
			cup[0] = cup[1];
			cup[1] = tmp;
		}
		else if(str[i] == 'B'){
			int tmp2;
			tmp2 = cup[1];
			cup[1] = cup[2];
			cup[2] = tmp2;
			//swap(cup[1],cup[2]);
		}
		else{
			int tmp3;
			tmp3 = cup[0];
			cup[0] = cup[2];
			cup[2] = tmp3;
		}
	}
	for(int i = 0; i < 3; i++){
		if(cup[i]){
			cout << i + 1;
		}
	}
}
