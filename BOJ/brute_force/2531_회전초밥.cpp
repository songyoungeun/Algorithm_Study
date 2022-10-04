#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, k, c;
int a[300002];
int chk[3002];
int flag, cnt, coupon, mx = 0;

int pro(){ //�����̵� ������  
	
	for(int i = 0; i < n; i++){
		flag = 0; //�ߺ��� ���� üũ 
		coupon = 1; //���� ���ð� �ִ��� Ȯ��  
		for(int j = i; j < i + k; j++){
			if(chk[a[j % n]] == 1) flag++; //�̹� ���� �ʹ��� ��� �ߺ� ǥ��  
			else chk[a[j % n]] = 1; //ó�� ���� �ʹ��� ��� üũ  
			
			if(a[j % n] == c) coupon = 0; // ���� ���� ������  
		}
		mx = max(mx, k - flag + coupon); //�������� ���� �� �ִ� �ִ����� - �ߺ����� + ��������  
		memset(chk, 0 sizeof(chk)); // �ʱ�ȭ  
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
