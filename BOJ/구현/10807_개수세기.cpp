#include <iostream>
using namespace std;

int main(){
	int n, v;
	cin >> n;
	int arr[n];
	for(int i = 0; i<n; i++) 
		cin >> arr[i];
	cin >> v;
	int cnt = 0;
	for(auto x : arr)
		if(x == v) cnt++;
	cout << cnt ;
}
