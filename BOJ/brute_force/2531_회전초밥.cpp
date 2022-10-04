#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, k, c;
int a[300002];
int chk[3002];
int flag, cnt, coupon, mx = 0;

int pro(){ //슬라이딩 윈도우  
	
	for(int i = 0; i < n; i++){
		flag = 0; //중복된 스시 체크 
		coupon = 1; //쿠폰 스시가 있는지 확인  
		for(int j = i; j < i + k; j++){
			if(chk[a[j % n]] == 1) flag++; //이미 먹은 초밥일 경우 중복 표시  
			else chk[a[j % n]] = 1; //처음 먹은 초밥일 경우 체크  
			
			if(a[j % n] == c) coupon = 0; // 쿠폰 스시 있을때  
		}
		mx = max(mx, k - flag + coupon); //연속으로 먹을 수 있는 최대접시 - 중복접시 + 쿠폰스시  
		memset(chk, 0 sizeof(chk)); // 초기화  
	}
	
	return mx;
}

void input(){
	cin >> n >> d >> k >> c;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	cout << pro();
}
