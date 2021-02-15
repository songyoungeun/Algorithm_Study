#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000002];
bool cmp(int a, int b){
	return b < a; //내림차순  
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr,arr+n,cmp);
	for(int i = 0; i < n; i++) cout << arr[i];	
}
