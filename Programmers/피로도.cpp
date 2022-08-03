#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int cnt = 0;
    vector<int> v;
    for(int i = 0; i < dungeons.size(); i++)
        v.push_back(i);
    do{
        int tmp = k;
        int answer = 0;
        for(int i = 0; i < v.size(); i++){
//            cout << v[i] <<' ';
//            cout << dungeons[v[i]][0] << ' ' << dungeons[v[i]][1]<<'\n';
            if(tmp >= dungeons[v[i]][0]){
                tmp -= dungeons[v[i]][1];
                answer++;
            }
            else break;
        }
        if(cnt < answer) cnt = answer;
    }while(next_permutation(v.begin(),v.end()));
    
    return cnt;
}
