#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[100001];
int dp[100001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	dp[0] = num[0];
	int res = dp[0];
	for(int i = 1; i < n; i++){
		dp[i] = max(dp[i-1] + num[i],num[i]);
		res = max(res,dp[i]);
	}
	
	cout << res;
} 
