#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> res(11,0);
    for(int num : numbers){
        res[num] = 1;
    }
    for(int i = 0; i < 10; i++){
        if(res[i] != 1)answer += i;
    }
    return answer;
}
