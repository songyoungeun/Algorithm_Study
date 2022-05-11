#include <iostream>
#include <algorithm>
using namespace std;

int n, a[505], sum[505][505], dy[505][505];

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
}
void preprocess(){
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			sum[i][j] = sum[i][j - 1] + a[j];
		}
	}
}
void pro(){
	for(int len = 2; len <= n; len++){
		for(int i = 1; i <= n - len + 1; i++){
			int j = i + len - 1;
			dy[i][j] = 0x7fffffff;
			for(int k = i; k < j; k++){
				dy[i][j] = min(dy[i][j], dy[i][k] + dy[k + 1][j] + sum[i][j]);
			}
		}
	}
	cout << dy[1][n] << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		input();
		preprocess();
		pro();
	}
	return 0;
}
