#include <iostream>

using namespace std;

int n;
int board[101][101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	for(int k = 0; k  < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(board[i][k] and board[k][j])
					board[i][j] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
