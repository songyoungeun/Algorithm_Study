#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t,n,m;
//int binary(int a, vector<int> &b){
//	int left = 0;
//	int right = b.size()-1;
//	while(left <= right){
//		int mid = (left + right) / 2;
//		if(a > b[mid]) left = mid + 1;
//		else right = mid -1;
//	}
//	return left;
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		int cnt = 0;
		vector<int> a(n);
		vector<int> b(m);

		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int bindex = 0;
		for(int i = 0; i < n; i++){
			while(bindex < m && b[bindex] < a[i]){
 				bindex++;
			}cnt += bindex;
		}
//		for(int i = 0; i < n; i++)
//			cnt += binary(a[i],b); // ÀÌºÐÅ½»ö 
		cout << cnt << '\n';
	}
}
