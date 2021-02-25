#include <iostream>
#include <algorithm>
using namespace std;

int n;
int triangle[502][502];
int d[502][502];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> triangle[1][1];
	d[1][1] = triangle[1][1];
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin >> triangle[i][j];
			d[i][j] = max(d[i-1][j-1],d[i-1][j]) + triangle[i][j];
		}
	}
	for(int i = 0; i <= n; i++)
//		d[n][0] = max(d[n][0], d[n][i]);
		cout << d[n][i];
	cout << *max_element(d[n], d[n] + (n+1));
			
			
}
