#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<long long> high(n);
	for(int i = 0; i < n; i++)
		cin >> high[i];
	sort(high.begin(),high.end());
	long long left = 0;
	long long right = high[high.size()-1];
	long long res = 0;
	while(left <= right){
		long long mid = (left + right) / 2;
		long long tree = 0;
		for(auto h : high){
			if(h - mid > 0){
				tree += h - mid;				
			}
		}
		if(m <= tree){
			res = max(res, mid); // m길이에 가까운 근사치 구하기  
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	cout << res;
} 
