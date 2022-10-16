//��Ʈ�� �κ�����
// & == and �Ѵ� 1�϶� 1
// | == or ���� 1�ϰ�� 1
// ^ == xor ������ 0 �ٸ��� 1 
// ~ == not ��Ʈ ���� 
// << left shift �ϳ� �̵��Ҷ����� ���ϱ�2 -> << 2�� ���ϱ� 2��2�� 
// >> right shift �ϳ� �̵������� ������ 2

//��Ʈ�� �̿��� �κ�����
//���Ұ� n���� ���� -> �κ������� �Ѱ��� 1 << n :  << 4 2��4�� = 16 
//n == 4 {a,b,c,d}
// 0000 0001 0010 0011 0100 .....1111 16��  
 
#include <iostream>

using namespace std;

void printSubsets(char arr[], int n){
	cout << (1 & (1 << 2)) << '\n';
	for(int i = 0; i < (1 << n); i++){ //(1 << 4) �� 16
		cout << "{";
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				cout << arr[j] << " ";
			}
				
		}
		
		cout << "}" << '\n'; 	
	}
}
int main(){
	char data[] = {'A','B','C','D'};
	printSubsets(data,4);//�迭,���Ұ���  
	return 0;
} 

//���տ� ��Ʈ���� Ȱ��

//������ ���Ұ���
#include <bitset>
int countBits(int n){
	bitset<32> set(n);
	return set.count(); //1�� ����  
}

int countBits(int n){
	int ret = 0;
	while(n){
		if(n & 1) ret++;
		n = n >> 1;
	}
	return ret; //1�� ��Ʈ ��  
} 
