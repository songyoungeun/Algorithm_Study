#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> con[n + 1];
    vector<int> dist(n + 1, -1);

    for(int i = 0; i < edge.size(); i++){
        con[edge[i][0]].push_back(edge[i][1]);
        con[edge[i][1]].push_back(edge[i][0]);
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int y : con[cur]){
            if(dist[y] == -1){
                dist[y] = dist[cur] + 1;
                q.push(y);
            }
        }
    }
    
    int node_max = *max_element(dist.begin(),dist.end());

    for(int ans : dist){

        if(ans == node_max) answer++;
    }
    return answer;
}
