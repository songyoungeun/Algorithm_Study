#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;

#define NM 100005

int N;
int a[NM], cnt[NM];

void input(){
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
}

void pro(){
	long ans = 0;
	for(int L = 1, R = 0; L <= N; L++){ //L마다 R을 최대한 옮김 
		// R을 옮길 수 있는 만틈 옮긴다. 
		while(R+1 <= N && cnt[a[R+1]] == 0){
			R++;
			cnt[a[R]]++;
		}
		//정답을 갱신  
		ans += R - L + 1;
		//L을 옮겨주면서 a[L]의 개수를 감소시킨다  
		cnt[a[L]]--;
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
