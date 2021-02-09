#include<iostream>
using namespace std;
int count[10001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,input;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> input;
		count[input]++;
	}
	for(int i = 1; i < 10001; i++){
		for(int j = 0; j < count[i]; j++){
			cout << i<<'\n';
		}
	}
} 

