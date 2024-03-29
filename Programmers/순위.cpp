#include <string>
#include <vector>
#include <iostream>
// #include <cstring>
int map[101][101];
using namespace std;
int solution(int n, vector<vector<int>> results) {
    int answer = 0, N = n;
    // memset(map, 0, sizeof(map));
    for(auto i : results) map[i[0]][i[1]] = 1;
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(map[i][k] && map[k][j]) map[i][j] = 1; //i->j로 갈때, k를 거쳐가는 길이 있다면
            }
        }
    }
    for(int i=1; i<=N; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++){
            if(map[i][j] || map[j][i]) cnt++; //i가 이길 사람 또는 질 사람
        }
        if(cnt == N-1) answer++;
    }
    return answer;
}
