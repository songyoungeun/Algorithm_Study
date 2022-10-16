//flood fill 알고리즘

#include <iostream>
using namespace std;

int N, Board[100][100];

void fill(int r, int c){
	if(r < 0 || r > N-1
	  || c < 0 || c > N-1) return;
	if(Board[r][c] != 0) return;
	
	Board[r][c] = 1;
	fill(r-1, c); //위
	fill(r+1, c); //아래
	fill(r, c-1); //왼 
	fill(r, c+1); //오 
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> Board[i][j];
		}
	}
	int sr, sc;
	cin >> sr >> sc;
	fill(sr,sc);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << Board[i][j] << ' ';
		}cout << '\n';
	}
	return 0;
} 
