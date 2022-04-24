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
		bool flag = false;//내려쳤나 안쳤나 판단  
		for(int i = 0; i < n; i++){
			if(i == k || s[i] <= 0) continue;
			s[k] -= w[i];
			s[i] -= w[k];
			flag = true; //계란 깸  
			rec_func(k + 1); //다음 계란 잡음  
			s[i] = s[i] + w[k];
			s[k] = s[k] + w[i];
		}
		//더이상 깰거 없어 n으로 이동  
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
