#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp1[1000010];
int dp2[1000010];

int solution(vector<int> money) {
    int n = money.size()-1;
    dp1[0] = money[0];
    dp1[1] = dp1[0];
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i = 2; i < n; i++){
        dp1[i] = max(dp1[i-2] + money[i],dp1[i-1]);
    }
    for(int i = 2; i <= n; i++){
        dp2[i] = max(dp2[i-2] + money[i],dp2[i-1]);
    }
    return max(dp1[n-1],dp2[n]);
    
}
