#include<iostream>

using namespace std;
int dp[1000005];
int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dp[1] = 0; //�ʱⰪ  
	for(int i = 2; i <= n; i++){
		d[i] = d[i-1] +1;
		if(i % 2 == 0) dp[i] = min(d[i], d[i/2]+1);
		if(i % 3 == 0) dp[i] = min(d[i], d[i/3]+1);

	}
	cout << d[n];
}
