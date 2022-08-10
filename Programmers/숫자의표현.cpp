#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    int num = (n + 1) / 2;
    int sum = 0, j = 1;
    for(int i = 1; i <= num; i++){
        //연속한 자연수 합이기에 가능
        sum += i;
        if(sum >= n){
            while(sum > n) sum -= j++;
            if(sum == n) answer++;
        }
    }
    //이미 answer에 1을 더해줬기 때문 
    if(n == 1) answer = 1;
    return answer;
}
