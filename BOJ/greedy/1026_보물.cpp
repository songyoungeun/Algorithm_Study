#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];

bool cmp(int x, int y){
	return x > y; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(b,b+n);
	sort(a,a+n,cmp); //sort(a,a+n)
	int s = 0;
	for(int i = 0; i < n; i ++){
		 s += a[i] * b[i]; // s += a[i] * b[n-1-i]
	}
	cout << s;
}
