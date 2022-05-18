#include <iostream>

using namespace std;

int t, MOD = 1000000009;
int dy[100005];

void input(){
	cin >> t;
}
void preprocess(){
//	dy[i] := i를 1,2,3의 합으로 표현하는 방법  
	dy[0] = 1;
	for(int i = 1; i <= 100000; i++){
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
		int res = 0;
		//홀수 개를 더한 경우
		for(int mid = 1; mid <= 3; mid++) //가운데에 mid를 더한 상황
			if(x - mid >= 0 && (x - mid) % 2 == 0){ //양쪽이 대칭을 이루게 더하기 위함  
				res += dy[(x - mid) / 2];
				res %= MOD;
			}
		//짝수 개를 더한 경우 mid가 0인경우
		if(x % 2 == 0){//양쪽이 대칭을 이루게 더하기 위함
			res += dy[x / 2];
			res %= MOD;
		}
		cout << res << '\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
