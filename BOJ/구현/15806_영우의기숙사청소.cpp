#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m ,k ,t;
int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};
int room[333][333];
bool chk[333][333][2];
vector<pair<int,int>>clean;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k >> t;
	clean.resize(k);
	queue<pair<int,int>>q;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		room[x][y] = 1;
		chk[x][y][0] = 1;
		q.push({x,y});
	}
	for(int i = 0; i < k; i++){
		int a, b;
		cin >>a >> b;
		clean[i] = {a, b};	
	}
	int cnt = 0;
    while (t--) { 
        int s = q.size();
        while (s--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            chk[x][y][cnt] = false;
 
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (!chk[nx][ny][(cnt+1) % 2]) {
                    chk[nx][ny][(cnt+1) % 2] = true;
                    q.push({ nx,ny });
                }
                
            }
        }
        cnt++;
    }
    for (int i = 0; i < k; i++) {
        int x = clean[i].first;
        int y = clean[i].second;
        if (chk[x][y][cnt%2]) {
        	cout << "YES"; return 0;
        }
    }
    cout << "NO";
}
