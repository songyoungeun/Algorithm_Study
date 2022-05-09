#include <iostream>
#include <algorithm>
using namespace std;

int a[301];
int dy[301][2];
int n;

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
}

void pro(){
	//초기값 구하기 
	dy[1][0] = 0;
	dy[1][1] = a[1];
	
	if(n >= 2){
		dy[2][0] = a[2];
		dy[2][1] = a[1] + a[2];
	}
	for(int i = 3; i <= n; i++){
		dy[i][0] = max(dy[i-2][0] + a[i], dy[i-2][1] + a[i]);
		dy[i][1] = dy[i-1][0] + a[i];
	}
	cout << max(dy[n][0], dy[n][1]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
}
