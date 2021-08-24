#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[501][501];
int ans;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    ans = dp[0][0] = triangle[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
            ans = max(ans, dp[i][j]);
        }

    }
    return ans;
}

