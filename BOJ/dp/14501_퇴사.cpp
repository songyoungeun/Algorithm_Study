#include <iostream>
#include <algorithm>
using namespace std;

int n; // 주어진 날짜
int t[16]; // 상담을 완료하는데 걸리는 기간
int p[16]; // 상담을 했을 때 받을 수 있는 금액
int d[16]; // 해당 날짜에 가질 수 있는 최대 금액
int ans = 0; // 최대 수익

int main(){
    //1. 문제 입력
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }

    // 2. DP 수행
    for(int i=1; i<=n; i++){
        // 1) i번째 날에 일을 했을 경우
        if(i+t[i] <=n+1){
            d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
            cout << "1: " << i+t[i]<< ' ' << d[i+t[i]] <<'\n';
            // 최대값 갱신
            ans = max(ans, d[i+t[i]]);
        }

        // 2) i번째 날에 일을 하지 않았을 경우
        d[i+1] = max(d[i+1], d[i]);
        cout << "2: " << i+1<< ' ' << d[i+1] <<'\n';
        // 최대값 갱신
        ans = max(ans, d[i+1]);
        cout << "3: " << ans <<'\n';
    }

    // 3. 출력
    printf("%d\n", ans);
}
