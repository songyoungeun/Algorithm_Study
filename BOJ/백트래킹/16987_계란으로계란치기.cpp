#include <iostream>
#include <algorithm>
using namespace std;

int n, answer, s[8], w[8];

void input(){
	cin >> n;
	for(int i = 0; i < n; i++)	
		cin >> s[i] >> w[i];
}

void rec_func(int k){
	
	if(k == n){		
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(s[i] <= 0){
				cout << i << ' ' << s[i] <<'\n';
				cnt++;
			}
		}
		answer = max(answer,cnt);
		return;
	}
	if(s[k] <= 0) rec_func(k + 1);
	else{
		bool flag = false;//�����Ƴ� ���Ƴ� �Ǵ�  
		for(int i = 0; i < n; i++){
			if(i == k || s[i] <= 0) continue;
			s[k] -= w[i];
			s[i] -= w[k];
			flag = true; //��� ��  
			rec_func(k + 1); //���� ��� ����  
			s[i] = s[i] + w[k];
			s[k] = s[k] + w[i];
		}
		//���̻� ���� ���� n���� �̵�  
		if(flag == false) rec_func(n);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	rec_func(0);

	cout << answer;
	return 0;
} 
