#include <iostream>

using namespace std;

int n, k, s, y;
int grade[7][2];
int room = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	while(n--){
		cin >> s >> y;
		grade[y][s] ++;
	}
	
	for(int i = 1; i <= 6; i++){
		for(int j = 0; j < 2; j++){
			if(grade[i][j] != 0){
				if(grade[i][j] % k == 0){
					room += grade[i][j] / k;

				}
				else{
					room += (grade[i][j] / k) + (grade[i][j] % k);

				}
			}
		}
	}
	cout << room;
}
