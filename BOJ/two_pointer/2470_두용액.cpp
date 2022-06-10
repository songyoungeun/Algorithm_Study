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

void pro(){
	sort(a + 1,a + 1 + n);
	int best_sum = 0x7fffffff;
	int v1 = 0, v2 = 0, L = 1, R = n;
	
	while(L < R){ //L == R�� ��Ȳ�̸� ����� �Ѱ� ���� ���̹Ƿ�  
		if(best_sum > abs(a[L] + a[R])){
			best_sum = abs(a[L] + a[R]);
			v1 = a[L];
			v2 = a[R];
		}
		if(a[L] + a[R] > 0) R--;
		else L++; 
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
