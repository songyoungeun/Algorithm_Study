//비트와 부분집합
// & == and 둘다 1일때 1
// | == or 둘중 1일경우 1
// ^ == xor 같으면 0 다르면 1 
// ~ == not 비트 반전 
// << left shift 하나 이동할때마다 곱하기2 -> << 2는 곱하기 2의2승 
// >> right shift 하나 이동때마다 나누기 2

//비트를 이용한 부분집합
//원소가 n개인 집합 -> 부분집합의 총개수 1 << n :  << 4 2의4승 = 16 
//n == 4 {a,b,c,d}
// 0000 0001 0010 0011 0100 .....1111 16개  
 
#include <iostream>

using namespace std;

void printSubsets(char arr[], int n){
	cout << (1 & (1 << 2)) << '\n';
	for(int i = 0; i < (1 << n); i++){ //(1 << 4) 는 16
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
	printSubsets(data,4);//배열,원소갯수  
	return 0;
} 

//집합에 비트연산 활용

//집합의 원소개수
#include <bitset>
int countBits(int n){
	bitset<32> set(n);
	return set.count(); //1인 갯수  
}

int countBits(int n){
	int ret = 0;
	while(n){
		if(n & 1) ret++;
		n = n >> 1;
	}
	return ret; //1인 비트 수  
} 
