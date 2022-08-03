#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool bfs(int a, int b, vector<string> map){
    vector<vector<bool>> visit(5,vector<bool>(5,false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{a,b},0});
    visit[a][b] = true;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(cnt == 2) continue;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
                if(visit[nx][ny] == false){
                    if(map[nx][ny] == 'O'){
                        visit[nx][ny] = true;
                        q.push({{nx,ny},cnt+1});
                    }
                    else if(map[nx][ny] == 'P'){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int find_answer(vector<string> map){
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == 'P'){
                if(bfs(i,j,map) == false){
                    return 0;
                }
            }
        }
    }
    return 1;
}
vector<int> Function(vector<vector<string>> map){
    vector<int> result;
    for(int i = 0; i < map.size(); i++){
        result.push_back(find_answer(map[i]));
    }
    return result;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    answer = Function(places);
    return answer;
}
