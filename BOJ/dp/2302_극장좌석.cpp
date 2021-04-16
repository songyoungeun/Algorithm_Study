#include <iostream>

using namespace std;

int n, m;
int d[41];
int vip[41];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	d[0] = d[1] = 1;
	for(int i = 2; i <= n; i++){
		d[i] = d[i-1] + d[i-2];
	}
	for(int i = 1; i <= m; i++) cin >> vip[i];
	int ans = 1;
	for(int i = 1; i <= m; i++){
		ans *= d[vip[i] - vip[i-1] - 1];
	}
	ans *= d[n - vip[m]];
	cout << ans;
}
