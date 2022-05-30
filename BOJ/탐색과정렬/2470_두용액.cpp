#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;	;
int a[100002]; 

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
}
int lower_bound(int A[], int L, int R, int x){
	int res = R + 1;
	while(L <= R){
		int mid = (L + R) / 2;
		if(A[mid] >= x){
			res = mid;
			R = mid -1;
		}
		else{
			L = mid +1;
		}
	}
	return res;
}

void pro(){
	sort(a + 1,a + 1 + n);
	int best_sum = 0x7fffffff;
	int v1 = 0, v2 = 0;
	for(int left = 1; left <= n - 1; left++){
		//-a[left]와 가까운 용액 찾기  
		int candidate = lower_bound(a, left + 1, n, -a[left]);
		
		//1. a[left] + a[candidate -1]
		if(left < candidate - 1 && abs(a[left] + a[candidate - 1]) < best_sum){
			best_sum = abs(a[left] + a[candidate - 1]);
			v1 = a[left];
			v2 = a[candidate - 1];
		}
		//2. a[left] + a[candidate]
		if (candidate <= n && abs(a[left] + a[candidate]) < best_sum) {
			best_sum = abs(a[left] + a[candidate]);
			v1 = a[left];
			v2 = a[candidate];
		}
	}
	cout << v1 << " " << v2;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
