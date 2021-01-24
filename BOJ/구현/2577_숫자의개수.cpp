#include <iostream>
#include <string>
using namespace std;
int arr[10];
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ans;
	ans = a * b * c;
	while (ans != 0){
		arr[ans % 10]++;
		ans /= 10;
	}

	for(int i = 0; i<10; i++) cout << arr[i] <<'\n';
		  
} 
