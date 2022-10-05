#include <iostream>

using namespace std;

int dp[10005][4];

void pro(){
	dp[1][1] = 1;
	dp[2][1] = 1; dp[2][2] = 1;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
	
	for(int i = 4; i <= 10000; i++){
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	pro();
	int t;
	cin >> t; 
	while(t--){
		int n;
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}
}
