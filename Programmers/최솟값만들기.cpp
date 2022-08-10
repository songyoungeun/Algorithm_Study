#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    //sort(B.rbegin(),B.rend()); 내림차순  
    for(int i = 0; i < A.size(); i++){
        answer += A[i] * B[i];
    }
    // return inner_product(A.begin(),A.end(),B.begin(),0); 
	//두 벡터의 내적 계산  
    return answer;
}
