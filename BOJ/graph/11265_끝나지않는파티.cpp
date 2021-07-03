#include <iostream>

using namespace std;

int party[500][500];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> party[i][j];
		}
	}
	for(int k = 1; k  <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(party[i][j] > party[i][k] + party[k][j])
					party[i][j] = party[i][k] + party[k][j];
			}
		}
	}
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(party[a][b] <= c) cout << "Enjoy other party" << '\n';
		else{
			cout << "Stay here" << '\n';
		}
	}
}
