#include <iostream>
#include <algorithm>

using namespace std;

int n, x, a[100001];

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> x;
}

void pro(){
	int ans = 0;
	sort(a + 1, a + 1 + n);
	for(int L = 1, R = n; L < R;){
		if(a[L] + a[R] == x) ans++;
		if(a[L] + a[R] >= x) R--;
		else L++;
	}
	cout << ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
} 
