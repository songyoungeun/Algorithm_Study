#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;	;
int a[20005], b[20005]; 

void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
}
int lower_bound(int A[], int L, int R, int x){
	int res = L - 1;
	while(L <= R){
		int mid = (L + R) / 2;
		if(A[mid] < x){
			res = mid;
			L = mid +1;
		}
		else{
			R = mid -1;
		}
	}
	return res;
}

void pro(){
	sort(b + 1,b + 1 + m);
	int ans = 0;
	
	//모든 a의 원소마다 b배열에 대해 이분탐색 필요  
	for(int i = 1; i <= n; i++){
		ans += lower_bound(b, 1, m, a[i]);
	
	}
	cout << ans << '\n'; 
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
		pro();
	}
	return 0;
}
