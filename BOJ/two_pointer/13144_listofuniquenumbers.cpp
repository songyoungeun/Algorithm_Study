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
	for(int L = 1, R = 0; L <= N; L++){ //L���� R�� �ִ��� �ű� 
		// R�� �ű� �� �ִ� ��ƴ �ű��. 
		while(R+1 <= N && cnt[a[R+1]] == 0){
			R++;
			cnt[a[R]]++;
		}
		//������ ����  
		ans += R - L + 1;
		//L�� �Ű��ָ鼭 a[L]�� ������ ���ҽ�Ų��  
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
