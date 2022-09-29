#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Gcd(int a, int b){ // 유클리드 호제법, 최대공약수 구하기  
	int x = max(a, b);
	int y = min(a, b);
	
	while(x % y != 0){
		int r = x % y;
		x = y;
		y = r;
	}
	return y;
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i = 1; i < arr.size(); i++){
        int gcd = Gcd(answer,arr[i]); //최대공약수구하기
        int lcm = (answer * arr[i]) / gcd; //최소공배수= 두 수의 곱 / 최대공약수
        answer = lcm;
    }
    return answer;
}

// 최소공배수 = 두 수의 곱 / 최대 공약수
//n개의 최소공배수 구하기는: 
//[ A , B , C , D ] 가 있을 때 이 A, B, C, D의 최소공배수는 얼마가 될까 ???
//2개씩 묶어서 구할 수가 있다.
//A와 B의 최소공배수 = x
//x와 C의 최소공배수 = y
//y와 D의 최소공배수 = z
//A, B, C, D의 최소공배수는 'z'가 된다는 것
