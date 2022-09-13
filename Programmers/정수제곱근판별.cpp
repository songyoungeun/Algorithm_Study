#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    if(sqrt(n) == (int)sqrt(n)){
        answer = pow(sqrt(n)+1, 2);
    }
    else answer = -1;
    
//	for(long long i = 1; i <= n; i++){
//	        if(i * i == n){
//	            answer = pow(i + 1,2);
//	            break;
//	        }
//	    }
//	if(!answer) answer = -1;


//    long long i;
//    for(i=1; i*i<=n; i++);
//    cout << i;
//    if((i-1)*(i-1)==n)
//    {
//        answer = i*i;
//    }
//
//    else{
//        answer = -1;
//    }
    return answer;
}
