#include <iostream>

using namespace std;

int dp[10001], n, m, memory[101], cost[101];
int sum_cost;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
		cin >> memory[i];
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
        sum_cost += cost[i];
    }
   	for(int i = 0; i < n; i++){
   		for(int j = sum_cost; j >= 0; j--){
   			if(j-cost[i] >= 0){
   				dp[j] = max(dp[j], dp[j-cost[i]] + memory[i]);
			   }
   			
		   }
	}
	for(int i = 0; i <= sum_cost; i++){
		if(dp[i] >= m){
			cout << i;
			break;
		}
	}
    return 0;
}
