#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x;
vector<int> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n;
	int input;
	for(int i = 0; i < n; i++){
		cin >> input; 
		v.push_back(input);
	} 
	cin >> x;
	sort(v.begin(),v.end());
	int l = 0, r = n-1, cnt = 0;
	while(1){
		if(l >= r) break;
		int result = v[l] + v[r];
		if(x == result){
			cnt++;
			l++;
			r--;
		}
		else if(result < x) l++;
		else r--;
	}cout << cnt;
	
}
