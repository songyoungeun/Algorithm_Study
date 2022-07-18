#include <iostream>

using namespace std;

int arr[1030][1030];
int n, m, k;

void pro(){

	while(m--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--, b--;
		cout << arr[c][d] - arr[a][d] - arr[c][b] + arr[a][b] << '\n';
	}
}
void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
			arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	pro();
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	return 0;
}
