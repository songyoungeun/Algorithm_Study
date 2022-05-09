#include <iostream>
#include <algorithm>
using namespace std;

int dy[1001][10];
int n;

void input(){
	cin >> n;
}

void pro(){
	//초기값 구하기 
	for(int i = 0; i < 10; i++){
		dy[1][i] = 1;
	}

	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k <= j; k++){
				dy[i][j] += dy[i-1][k];
				dy[i][j] %= 10007;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 10; i++){
		ans += dy[n][i];
		ans %= 10007;
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
}
