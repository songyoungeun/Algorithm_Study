#include <iostream>
#include <algorithm>
using namespace std;
int arr[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n ;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int mx = 0;
	for(int i = n-1; i > 0; i--){
		swap(*max_element(arr, arr+i+1), arr[i]);
	}
	for(int i = 0; i < n; i++) cout << arr[i] <<'\n';
}
