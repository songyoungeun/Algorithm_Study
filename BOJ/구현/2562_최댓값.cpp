#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int m = -1;
	int cnt;
	for(int i = 1; i < 10; i++){
		cin >> n;
		if(m < n){
			m = n;
			cnt = i;
		}
	}
	cout << m << '\n' << cnt;
}
