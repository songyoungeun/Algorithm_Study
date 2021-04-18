#include <iostream>

using namespace std;
typedef long long ll;
#define mod 1000000000

int n;
ll dp[101][101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}
	dp[1][0] = 0;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= 9; j++){
			if(j == 0) dp[i][j] = dp[i-1][j+1] % mod;
			else if(j == 9) dp[i][j] = dp[i-1][j-1] % mod;
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
			
		}
	}
	ll ans = 0;
	for(int i = 0; i < 10; i++){
		ans += dp[n][i];
	}	
	cout << ans % mod;
}
