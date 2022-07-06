#include <iostream>

using namespace std;

int n, m;
int arr[4005];

void pro(int a, int b, int c){
	if(a == 1){
		arr[b] = c;
	}
	else if(a == 2){
		for(int i = b; i <= c; i++){
			if(!arr[i]) arr[i] = 1;
			else arr[i] = 0;
		}
	}
	else if(a == 3){
		for(int i = b; i <= c; i++){
			arr[i] = 0;
		}		
	}
	else{
		for(int i = b; i <= c; i++){
			arr[i] = 1;
		}		
	}

}
void input(){
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		pro(a, b, c);
	}
	for(int i = 1; i <= n; i++){
		cout << arr[i] << ' ';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();

	return 0;
} 
