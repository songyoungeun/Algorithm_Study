#include <iostream>

using namespace std;

int Row, Col, Board[100][100]; //이차원 배열 
int main(){
	cin >> Row >> Col;
	for(int i = 0; i < Row; i++){
		for(int j = 0; j < Col; j++){
			cin >> Board[i][j];
		}
	}
} 
//int N, Score[100]; //일차원배열  
//
//int main(){
//	cin >> N;	
//	for(int i = 0; i < N; ++i){
//		cin >> Score[i];
//	}
//	for(int i = 0; i < N; ++i){
//		cout << Score[i] <<' ';
//	}
//} 

