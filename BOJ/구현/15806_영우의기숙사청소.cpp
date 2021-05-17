#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m ,k ,t;
int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};
int room[300][300];
bool chk[300][300][2];
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
		room[x-1][y-1] = 1
		chk[x-1][y-1][0] = 1;
		q.push({x-1,y-1});
	}
	for(int i = 0; i < k; i++){
		int a, b;
		cin >>a >> b;
		clean[i] = {x-1, y-1};	
	}
	int cnt = 0;
    while (t--) {
        int s = q.size();
        while (s--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            check[x][y][cnt] = false;
 
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (!check[nx][ny][(cnt+1) % 2]) {
                        check[nx][ny][(cnt+1) % 2] = true;
                        q.push({ nx,ny });
                    }
                }
            }
        }
        cnt++;
    }
    for (int i = 0; i < k; i++) {
        int x = clean[i].first;
        int y = clean[i].second;
        if (check[x][y][cnt%2]) {
            puts("YES"); return 0;
        }
    }
    puts("NO");
}
