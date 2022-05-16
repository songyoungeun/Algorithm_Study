#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define NM 10001

int n;
int dy[NM][2];
vector<int> con[NM];
int num[NM];

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
}

void dfs(int x, int par){
	dy[x][1] = num[x];
	
	for(int y : con[x]){
		if(y == par) continue;
		dfs(y, x);
		dy[x][0] += max(dy[y][0], dy[y][1]);
		dy[x][1] += dy[y][0];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	dfs(1,-1);
	cout << max(dy[1][0], dy[1][1]);
	cout << '\n' << dy[2][0];
	return 0;
}
