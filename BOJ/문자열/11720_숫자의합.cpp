#include <iostream>
#include <string>

using namespace std;

int n;
int ans;

void input(){
	cin >> n;
	string num;
	cin >> num;
	
	for(int i = 0; i < n; i++){
		ans += num[i] - '0';
	}
	cout << ans;
}
//void pro(){
//	//1
//	int num;
//	cin >> num;
//	char arr[num];
//	cin >> arr;
//	int sum = 0;
//	for(int i = 0; i < num; i++){
//		sum += arr[i] -'0';
//	}
//	cout << sum;
//	//2
//	char num2;
//	for(int i = 0; i < num; i++){
//		cin >> num2;
//		sum += (num2 - '0');
//	}
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	
} 
