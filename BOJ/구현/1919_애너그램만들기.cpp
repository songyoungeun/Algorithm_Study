#include <iostream>
#include <string>

using namespace std;

int s1[26];
int s2[26];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;

	cin >> a >> b;
  	for(int i = 0; i< a.length(); i++){
		s1[a[i] - 'a']++;
	}
	for(int i = 0; i< b.length(); i++){
		s2[b[i] - 'a']++;
	}
	int cnt = 0;
	for(int i = 0; i<26; i++){
		if(s1[i] != s2[i]){
			cnt += abs(s1[i] - s2[i]);
		}
	}
	cout << cnt;
	
	
}
