#include <iostream>

using namespace std;

int t, MOD = 1000000009;
int dy[100005];

void input(){
	cin >> t;
}
void preprocess(){
//	dy[i] := i�� 1,2,3�� ������ ǥ���ϴ� ���  
	dy[0] = 1;
	for(int i = 1; i <= 100000; i++){
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
		int res = 0;
		//Ȧ�� ���� ���� ���
		for(int mid = 1; mid <= 3; mid++) //����� mid�� ���� ��Ȳ
			if(x - mid >= 0 && (x - mid) % 2 == 0){ //������ ��Ī�� �̷�� ���ϱ� ����  
				res += dy[(x - mid) / 2];
				res %= MOD;
			}
		//¦�� ���� ���� ��� mid�� 0�ΰ��
		if(x % 2 == 0){//������ ��Ī�� �̷�� ���ϱ� ����
			res += dy[x / 2];
			res %= MOD;
		}
		cout << res << '\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;
}
