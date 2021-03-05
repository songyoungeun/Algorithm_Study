#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i = 0; i < citations.size(); i++){
        int h_index = citations.size() - i;
        if(citations[i] == h_index){
        	answer = h_index;
        	break;	
		}
    }
    return answer;
}
