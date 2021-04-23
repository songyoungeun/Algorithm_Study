#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer, man = 0;
    long long low = (long long)times[0];
	long long high = (long long)times[times.size()-1] * n;
    while(low <= high){
        long long man = 0;
        long long mid = (low + high) / 2;
        for(auto t : times){
            man += mid / t;
        }
        if(n <= man){
            high = mid -1;
            answer = mid;
        }
        else{
            low = mid +1;
        }
    }
    return answer;
}
