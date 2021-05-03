#include <iostream>

using namespace std;
const int INF = 9999999;
int n,m,a,b;
int dist[501][501];

void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dist[i][j] = INF;
		}
	}
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		dist[a][b] = 1;
	}
	floyd();
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << dist[i][j] <<' ';
		}cout << '\n';
	}	
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			if(dist[i][j] != INF || dist[j][i] != INF){
				cout << "1: "<<i << j <<'\n';
				cout << "2: "<<dist[i][j] <<' '<< dist[j][i] <<'\n';
				cnt++;
			}
		}
		if(cnt == n-1) ans++;
		cout << "3: "<<cnt << ans <<'\n';
	}
	cout << ans;
}
