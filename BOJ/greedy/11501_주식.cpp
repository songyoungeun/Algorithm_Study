#include <iostream>

using namespace std;

int t, n;
int d[1000001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> d[i];
		}
		long long res = 0;
		int last = d[n - 1];
		
		for(int i = n-2; i >= 0 ; i--){
			if(last > d[i]){
				res += (last - d[i]);
			}
			else{
				last = d[i];
			}
		}
		if(res <= 0)cout << 0 <<'\n';
		else cout <<res << '\n';
	}
}
