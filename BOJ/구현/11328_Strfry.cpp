#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
	int n;
	int s1[26];
	bool res;
	string a, b;
	cin >> n;

	while(n--){
		cin >> a >> b;
		res = true;
		fill(s1,s1+26,0);

		for(int i = 0; i< a.length(); i++){
			s1[a[i] - 'a']++;
			s1[b[i] - 'a']--;
		}
		for(int i = 0; i<26; i++){
			if(s1[i] != 0){
			 res = false;
			 break;
			}
		}
		if(res) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
	
	}

	return 0;

}
