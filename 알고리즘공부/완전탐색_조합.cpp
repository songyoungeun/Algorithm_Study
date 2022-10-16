//경우의 수
//- 순열: 선택 순서가 결과에 영향미침 (만들수 있는 가장 큰 두자리수 구하기)
//- 조합: 선택 순서가 결과에 영향 안줌 (두 수 더했을때 가장 큰합 구하기) 
// 조합이 순열보다 경우의 수가 적어 시간 덜 걸림  
#include <iostream>
#include <algorithm>

using namespace std;

int n = 4;
int nums[] = {1,2,3,4};

int solve(int pos, int cnt, int val){

//	pos : 현재위치 cnt : 선택갯수
	if(cnt == 2) return val;
	if(pos == n) return -1; 
	int ret = 0;
	ret = max(ret, solve(pos + 1, cnt + 1, val + nums[pos])); //선택하고 
	ret = max(ret, solve(pos + 1, cnt , val));  //선택안하고 
	
//	1 -> 2 :3
//	  -> - (선택안하고) -> 3 : 4
//	                    -> - (선택안하고) -> 4 :5 
	return ret;
}

int main(){
	cout << solve(0,0,0) <<'\n'; // 가장 큰 두수의 합 구하기, 조합  
	return 0;
}
 
