#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int x : scoville) pq.push(x);
    while(pq.top() < K){
        if(pq.size() == 1) return -1;
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        int new_num = a + (b * 2);
        pq.push(new_num);
        answer++;
        
    }
    return answer;
}
