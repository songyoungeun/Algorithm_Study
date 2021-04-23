#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[4][4001];
vector<int> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			cin >> arr[j][i];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			v.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(v.begin(),v.end());
	
	long long res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int num = arr[0][i] + arr[1][j];
			int low = lower_bound(v.begin(),v.end(),-num) - v.begin();
			int high = upper_bound(v.begin(),v.end(),-num) - v.begin();	
			if(-num == v[low]){
				res += (high - low);
			}	
		}
	}
	cout << res;
}
