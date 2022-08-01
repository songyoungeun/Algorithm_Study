#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int map[110][110];

int Turning(int x, int y, int xx, int yy){
    int min_num;
    int tmp = map[x][y];
    min_num = tmp;

    for(int i = x; i < xx; i++){ //���ʺ�
        int cmp = map[i][y];
        min_num = min(min_num, cmp);
        map[i][y] = map[i + 1][y];
    }

    for(int i = y; i < yy; i++){ //�غ�
        int cmp = map[xx][i];
        min_num = min(min_num, cmp);
        map[xx][i] = map[xx][i + 1];
    }
    for(int i = xx; i > x; i--){ //������
        int cmp = map[i][yy];
        min_num = min(min_num, cmp);
        map[i][yy] = map[i - 1][yy];
    }
    for(int i = yy; i > y; i--){ //����
        int cmp = map[x][i];
        min_num = min(min_num, cmp);
        map[x][i] = map[x][i - 1];
    }
    map[x][y + 1] = tmp; //map[x][y]�� ��������� ����� ������ ����
    return min_num;
    
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int num = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            map[i][j] = num++;
        }
    }

    for(int i = 0; i < queries.size(); i++){
        int x = queries[i][0]; x--;
        int y = queries[i][1]; y--;
        int xx = queries[i][2]; xx--;
        int yy = queries[i][3]; yy--;
        answer.push_back(Turning(x,y,xx,yy));     
    }
    return answer;
}
