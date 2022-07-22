#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int rank[7] = {0,6,5,4,3,2,1};

    int zero = 0;
    int min_cnt = 0;
    for(auto k : lottos){
    	if(k == 0) zero++;
	}
    for(int i = 0; i < lottos.size(); i++){
        for(int j = 0; j < win_nums.size(); j++){
        	if(lottos[i] == win_nums[j]){
        		min_cnt++;
        		break;
			}
		}
    }
    int max_cnt = zero + min_cnt;
	answer.push_back(rank[max_cnt]);
	answer.push_back(rank[min_cnt]);	

    
    return answer;
}
