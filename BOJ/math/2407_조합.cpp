#include <iostream>
using namespace std;

int n, m;
string combi[105][105];

string addNum(string a, string b){
	//string으로 숫자 더하기 
	string result = "";
	if(a.length() > b.length()){
		while(a.length() != b.length()){
			b = '0' + b;
		}
	}
	else{
		while(a.length() != b.length()){
			a = '0' + a;
			cout << "a: " << a;
		}
	}
	int sum = 0;
	for(int i = a.length()-1; i >= 0; i--){
		sum += a[i] - '0';
		sum += b[i] - '0';
		result = to_string(sum % 10) + result;
		
		if(sum >= 10){
			sum = 1;
		}
		else{
			sum = 0;
		}
	}
	if(sum == 1){
		return '1' + result;
	}
	return result;
}
void makeCombi(){
	//n,m까지 채워넣기  
	combi[0][0] = "1";
	combi[1][0] = combi[1][1] = "1";
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; i <= m; j++){
			if(i == j || j == 0) combi[i][j] = "1";
			else{
				combi[i][j] = addNum(combi[i-1][j-1], combi[i-1][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);

	cin >> n >> m;
	
	makeCombi();
	cout << combi[n][m];
	
	return 0;
}
