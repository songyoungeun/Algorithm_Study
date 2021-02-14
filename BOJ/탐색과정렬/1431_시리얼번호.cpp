#include <iostream>
#include <algorithm>
using namespace std;
string serial[1001];
int n;
int sum(string c){
	int sum = 0;
	for(int i = 0; i < c.length(); i++){
		if(c[i] - '0' <=9 && c[i] - '0' >=0) {
			sum += c[i] - '0';
		}
	}

	return sum;
}
bool cmp(string a, string b){
	int sum1,sum2 = 0;
	if(a.length() < b.length()) return a.length() < b.length(); 
	else if(a.length() == b.length()){
		int sum1 = sum(a);
		int sum2 = sum(b);
		if(sum1 != sum2) sum1 < sum2;
		else return a < b; 
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> serial[i];	
	}	
	sort(serial, serial+n,cmp);
	for(int i = 0; i < n; i++){
		cout << serial[i] << '\n';	
	} 
}
