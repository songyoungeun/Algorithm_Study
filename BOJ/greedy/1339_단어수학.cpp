#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int alpha[26];
vector<string> v;

bool cmp(int a, int b){
	if(a > b) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		v.push_back(str);
	}
	for(int i = 0; i < n; i++){
		string s = v[i];
		int pow = 1;
		for(int j = s.length()-1; j >= 0; j--){
			int tmp = s[j] - 'A';
			alpha[tmp] += pow;
			pow *= 10;
		}
	}
	sort(alpha, alpha + 26, cmp);
	int ans = 0;
	int num = 9;
	for(int i = 0; i < 26; i++){
		if(alpha[i] == 0) break;
		ans += alpha[i] * num;
		num--;
	}
	cout << ans;
}
