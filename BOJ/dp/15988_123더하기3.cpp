#include <iostream>

using namespace std;

int t, MOD = 1000000009;
int dy[1000005];

void input(){
	cin >> t;
}
void preprocess(){
//	dy[i] := i를 1,2,3의 합으로 표현하는 방법  
	dy[0] = 1;
	for(int i = 0; i < 1000000; i++){
		dy[i] = dy[i - 1]; // 마지막에 1을 더하는 경우의 수 
		if(i - 2 >= 0) dy[i] += dy[i - 2]; //마지막에 2를 더하는 경우의 수  
		dy[i] %= MOD;
		if(i - 3 >= 0) dy[i] += dy[i - 3]; //마지막에 3을 더하는 경우의 수  
		dy[i] %= MOD;
	}
}
void pro(){
	preprocess();
	while(t--){
		int x;
		cin >> x;
		cout << dy[x] << '\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
