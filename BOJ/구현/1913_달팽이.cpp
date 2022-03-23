#include <iostream>
#include <algorithm>
#include <iterator>


using namespace std;
//�� �� �� ��
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int map[1001][1001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int s = n * n;
	int y = -1, x = 0, dir = 0;
	int ansy = 0, ansx = 0;
//	function<bool(int,int)> inrange = [&](int y, int x) -> bool { 
//        return 0 <= y && y < n && 0 <= x && x < n; 
//    };
	while(s > 0){
		int ny = y + dy[dir];
		int nx = x + dx[dir];
//		if(!inrange(ny, nx) || map[ny][nx] != 0) {
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] != 0){
			//������ ����ų� �̹� ä���� ���� �� ������ ��ȯ  
			dir = (dir + 1) % 4;
			continue;
		}
		
		y = ny; x = nx;
		map[y][x] = s; //ū�� ���� ä������ 0,0 ����  
		if(s == k){
			ansy = y + 1;
			ansx = x + 1;
		}
		s--;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << map[i][j] << ' ';
		}cout << '\n';
	}
	cout << ansy <<  ' '<< ansx;
}
 
