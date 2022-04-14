#include<iostream>
using namespace std;

int pro(int n){
	int value = 1;
	int cnt = 6;
	int ans = 1;
	while(1){
		if(value >= n){
			cout << ans;
			return 0;
		}
		value += cnt;
		cnt += 6;
		ans++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	pro(n);
}
