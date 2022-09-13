#include<vector>
#include<queue>
#include<iostream>

using namespace std;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int dist[100][100];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    int n = maps.size();
    int m = maps[0].size();
    dist[0][0] = 1;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(maps[i][j] == 1) dist[i][j] = 1;
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int idx = 0; idx < 4; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(maps[nx][ny] == 0) continue;
            if(dist[nx][ny] != 0) continue;
            // cout << nx << " " << ny << '\n';

            dist[nx][ny] = dist[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }
    //     }
    // }
    
    return dist[n-1][m-1] == 0 ? -1 : dist[n-1][m-1];
}
