#include <iostream>

using namespace std;

int s[1000001],d[10001],p[1000001];
int n, k;
void input(){

	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}
	while(k--){
		for(int i = 1; i <= n; i++){
			int a = s[i];
			int b = d[i];
			p[b] = a;		
		}
		for(int i = 1; i <= n; i++)
			s[i] = p[i];
	}


}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	for(int i = 1; i <= n; i++){
		cout << p[i] <<' '; 
	}
	return 0;

}
