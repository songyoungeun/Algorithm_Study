//경우의 수
//- 순열: 선택 순서가 결과에 영향미침 (만들수 있는 가장 큰 두자리수 구하기)
//- 조합: 선택 순서가 결과에 영향 안줌 (두 수 더했을때 가장 큰합 구하기) 

#include <iostream>
#include <algorithm>

using namespace std;

int n = 4;
int nums[] = {1,2,3,4};

int solve(int cnt, int used, int val){

	if(cnt == 2) return val; // 두수 만들었을때  
	int ret = 0;

	for(int i = 0; i < n; ++i){ //모든 경우의 수  

		if(used & (1 << i)) continue;

		ret = max(ret, solve(cnt + 1, used | (1 << i), val * 10 + nums[i]));
		
	}
//	1 - 2,3,4
//	2 - 1,3,4
//	3 - 1,2,4
//	4 - 1,2,3
	return ret;
}

int main(){
	cout << solve(0,0,0) <<'\n'; // 가장 큰 두자리수 구하기 ,순열 
	return 0;
}
 
