#include <iostream>
using namespace std;

int Row, Col, Board[100][100], Sr, Sc;

void cross(){
	if(Board[Sr][Sc] != 0)return;
	Board[Sr][Sc] = 1;
	for(int i = Sr - 1; i >= 0; i--){
		if(Board[i][Sc] != 0) break;
		Board[i][Sc] = 1;
	} //���� �ö󰡱� 
	for(int i = Sr +1 1; i < Row; i++){
		if(Board[i][Sc] != 0) break;
		Board[i][Sc] = 1;
	} //��������  ���� ���� 
	for(int j = Sc - 1; j >= Row; j--){
		if(Board[Sr][j] != 0) break;
		Board[Sr][j] = 1;
	} //����
	for(int j = Sc + 1; j < Col; j++){
		if(Board[Sr][j] != 0) break;
		Board[Sr][j] = 1;
	} //���� ��  
}
int main(){
	cin >> Row >> Col;
	for(int i = 0; i < Row; i++){
		for(int j = 0; j < Col; j++){
			cin >> Board[i][j];
		}
	}
	cin >> Sr >> Sc; //������ġ 
	for(int i = 0; i < Row; i++){
		for(int j = 0; j < Col; j++){
			cout << Board[i][j] << ' ';
		}cout << '\n';
	}
	cross(); 
} 
