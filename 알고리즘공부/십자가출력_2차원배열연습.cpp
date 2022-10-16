#include <iostream>
using namespace std;

int Row, Col, Board[100][100], Sr, Sc;

void cross(){
	if(Board[Sr][Sc] != 0)return;
	Board[Sr][Sc] = 1;
	for(int i = Sr - 1; i >= 0; i--){
		if(Board[i][Sc] != 0) break;
		Board[i][Sc] = 1;
	} //위로 올라가기 
	for(int i = Sr +1 1; i < Row; i++){
		if(Board[i][Sc] != 0) break;
		Board[i][Sc] = 1;
	} //내려가기  내려 가기 
	for(int j = Sc - 1; j >= Row; j--){
		if(Board[Sr][j] != 0) break;
		Board[Sr][j] = 1;
	} //왼쪽
	for(int j = Sc + 1; j < Col; j++){
		if(Board[Sr][j] != 0) break;
		Board[Sr][j] = 1;
	} //오른 쪽  
}
int main(){
	cin >> Row >> Col;
	for(int i = 0; i < Row; i++){
		for(int j = 0; j < Col; j++){
			cin >> Board[i][j];
		}
	}
	cin >> Sr >> Sc; //시작위치 
	for(int i = 0; i < Row; i++){
		for(int j = 0; j < Col; j++){
			cout << Board[i][j] << ' ';
		}cout << '\n';
	}
	cross(); 
} 
