#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string n;
int num[11];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int set = 0;
	for(int i = 0; i < n.length(); i++){
		if(n[i] == '6' || n[i] == '9'){
			num[6]++;
			set = max(set, (num[6] /2 + num[6] %2));
		}
		else{
			num[n[i] - '0']++;
			set = max(set, num[n[i] - '0']);
		}
	}

	
	cout << set ; 

}
