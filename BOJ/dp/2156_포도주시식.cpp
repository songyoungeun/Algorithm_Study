#include <iostream>
#include <algorithm>

using namespace std;

int n;
int wine[10001];
int dp[10001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> wine[i];
	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	
	for(int i = 2; i < n; i++){
		dp[i] = max(dp[i-2] + wine[i], dp[i-3] + wine[i] + wine[i-1]);
		dp[i] = max(dp[i-1], dp[i]);
	}		
	cout << dp[n-1];
}
