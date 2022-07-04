#include <iostream>

using namespace std;

int board[5][5];
bool used[5][5];

bool bingo(){
	int line = 0;
	
	bool bingo = true;
	
	for(int i = 0; i < 5; i++){
		bingo = true;
		for(int j = 0; j < 5; j++){ //가로 확인 
			bingo &= used[i][j];
		}
		if(bingo) line++;
		
		bingo = true;
		for(int j = 0; j < 5; j++){ //세로 확인  
			bingo &= used[j][i];
		}
		if(bingo) line++;
	}
	
	bingo = true;
    for(int i=0;i<5;i++){ //대각선  
        bingo &= used[i][i];
    }
    if(bingo) line++;
    
    bingo = true;
    for(int i=0;i<5;i++){ //대각선  
        bingo &= used[4-i][i];
    }
    if(bingo) line++;

    return line >= 3;
}
void marking(int num){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(board[i][j] == num){
				used[i][j] = true;
				return;
			}
		}
	}
}
void input(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> board[i][j];
		}
	}
	for(int i = 1; i <= 25; i++){
		int x; cin >> x;
		marking(x);
		if(bingo()){
			cout << i;
			return 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	return 0;
}
