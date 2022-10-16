#include <iostream>

using namespace std;

int N, Arr[10];
//�μ��� ���� 7�� ����� ��  
//6
// 1 2 3 4 5 6
// 1 6 / 3 4 / 5 2 -> 3
int countBits(int n){
	int ret = 0;
	while(n){
		if(n & 1) ret++;
		n = n >> 1;
	}
	return ret; //1�� ��Ʈ ��  
} 

int solve(){ //�μ��� ���� 7�� ����� �� 
	int ret = 0;
//	cout <<(1 << 6); // 64
	for(int i = 0; i < (1 << N); i++){
//		000 000/ 000 001/ 000 011 / ...100 001(1 + 6 = 7)
		if(countBits(i) != 2) continue;
		//���Ұ� �ΰ��� ���� ó���� : �μ� ���� 
		int sum = 0;
		for(int j = 0; j < N; j++){
			if(i & 1 << j){
//				cout << "j: " << j << '\n';
				sum += Arr[j];
			}
//			cout << "sum: " << sum << '\n';
		}
		if(sum == 7) ret++;
	}
	return ret;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> Arr[i];
	cout << solve() << '\n';
	return 0;
}
