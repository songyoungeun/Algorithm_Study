#include <iostream>
#include <algorithm>

using namespace std; 
int arr[1000005];
int n;
void pro(){
	sort(arr, arr + n);
	cout << arr[0] << " " << arr[n - 1] << '\n';
}
void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		arr[i] = a;
	}
	pro();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
	}
}
