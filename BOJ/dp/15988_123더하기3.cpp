#include <iostream>

using namespace std;

int t, MOD = 1000000009;
int dy[1000005];

void input(){
	cin >> t;
}
void preprocess(){
//	dy[i] := i�� 1,2,3�� ������ ǥ���ϴ� ���  
	dy[0] = 1;
	for(int i = 0; i < 1000000; i++){
		dy[i] = dy[i - 1]; // �������� 1�� ���ϴ� ����� �� 
		if(i - 2 >= 0) dy[i] += dy[i - 2]; //�������� 2�� ���ϴ� ����� ��  
		dy[i] %= MOD;
		if(i - 3 >= 0) dy[i] += dy[i - 3]; //�������� 3�� ���ϴ� ����� ��  
		dy[i] %= MOD;
	}
}
void pro(){
	preprocess();
	while(t--){
		int x;
		cin >> x;
		cout << dy[x] << '\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
