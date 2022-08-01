#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	for(int i = 2; i < n; i++){
		if(!((n-1) % i)) // n = 10 -> 9로 나눠떨어지는거 찾기
		{
			answer = i;
			break; 
		 } 
	}
//    int answer = 9999999, tmp = 0;
//    for(int i = 1; i < n; i++){
//        if(n % i == 1){
//            tmp = i;
//            answer = min(answer,tmp);
//        }
//    }
    return answer;
}
