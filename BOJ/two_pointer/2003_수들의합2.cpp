#include <iostream>

using namespace std;

int n, m;
int a[10001]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int sum = a[0];
	int left = 0, right = 0;
	int ans = 0;
	while(left <= right and right < n){
		if(sum < m){
			right++;
			if(right >= n) break;
			sum += a[right];
		}
		else if(sum == m){
			ans++;
			right++;
			sum += a[right];
		}
		else{
			sum -= a[left];
			left++;
			//L이 R을 역전하면 l에서 부터 다시 시작 
			if(left > right){
				right = left;
				if(left < n) sum = a[right];
			}
		}
	}
	cout << cnt;
}
