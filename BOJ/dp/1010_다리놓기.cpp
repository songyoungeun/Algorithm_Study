#include <iostream>

using namespace std;

long long dp[33][33];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= m; i++){
			dp[1][i] = i;
		}
		for(int i = 2; i <= n; i++){
			for(int j = 2; j <= m; j++){
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
			}
		}
		cout << dp[n][m] << '\n';
	}
}
