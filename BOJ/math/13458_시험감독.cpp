#include <iostream>
#include <algorithm>
using namespace std;

int n, b, c;
int a[1000005];
long long sum;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;
	for(int i = 0; i < n; i++){
		a[i] -= b;
		sum++;
		if(a[i] > 0){
			if(a[i] % c == 0){
				sum += a[i] / c;
			}
			else{
				sum += (a[i] /c) +1;
			}
		}
	}
	cout << sum;	
}
