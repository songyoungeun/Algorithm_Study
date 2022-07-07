#include <iostream>
#include <vector> 
using namespace std;

const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1}; 
int n, m, r;
int arr[333][333];
bool used[333][333], used2[333][333];
void pro(){
	for(int i = 0; i < n; i++){
		int y = i, x = i, dir = 0;
        vector<int> cur;
        cur.push_back(arr[y][x]);
        used[y][x] = true;
        while(dir < 4){
            int qy = y + dy[dir];
            int qx = x + dx[dir];
            if(0 > qy || qy >= n || 0 > qx || qx >= m || used[qy][qx]){
                dir++;
                continue;
            }
            y = qy, x = qx;
            used[y][x] = true;
            cur.push_back(arr[y][x]);
        }
		int L = cur.size();
        int idx = (L - r % L) % L;
        y = i, x = i, dir = 0;
        used2[y][x] = true;
        arr[y][x] = cur[idx];
        if(++idx == (int)cur.size()) idx = 0;
        while(dir < 4){
            int qy = y + dy[dir];
            int qx = x + dx[dir];
            if(0 > qy || qy >= n || 0 > qx || qx >= m || used2[qy][qx]){
                dir++;
                continue;
            }
            y = qy, x = qx;
            used2[y][x] = true;
            arr[y][x] = cur[idx];
            if(++idx == (int)cur.size()) idx = 0;
        }
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << arr[i][j] <<' ';
		}
		cout << '\n';
	}
}
void input(){
	cin >> n >> m >> r;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	pro();
	return 0;	
}
