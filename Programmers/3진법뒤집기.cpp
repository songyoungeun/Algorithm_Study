#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num;
    while(n > 0){
        num.push_back(n % 3);
        n /= 3;
    }
//    for(int i = 0; i < num.size(); i++){
//        int a = num.size() - (i + 1);
//        int b = pow(3,a);
//        answer += num[i] * b;
//    }
	int k = 1;
	while(!num.empty()){
		answer += k * num.back();
		num.pop_back();
		k *= 3;
	}
    return answer;
}
