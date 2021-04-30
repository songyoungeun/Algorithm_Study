#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

int n;
long long fact[21];
bool chk[21];

int main() {

	cin >> n;
	fact[1] = 1;
	for (int i = 2; i < 21; i++)
	{
		fact[i] = fact[i - 1] * i;
	}
	int num;
	int cnt = 0;
	cin >> num;
	if (num == 1) {
		long long k;
        cin >> k;
        vector<int>a(n);
        
        for(int i = 0; i < n; i++){
        	for(int j = 1; j <= n; j++){
        		if(chk[j]) continue;
        		if(fact[n - i -1] < k){
        			k -= fact[n - i - 1];
				}
				else{
					a[i] = j;
					chk[j] = 1;
					break;
				}
			}
		}
		for(int i = 0; i < n; i++) 
			cout << a[i] <<' ';
	}
	else {
		vector<int>a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		long long ans = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = 1; j < a[i]; j++){
				if(!chk[j]){
					ans += fact[n - i - 1];
				}
				chk[a[i]] = 1;
			}
		}
		cout << ans +1 <<'\n';
	}

	return 0;
}
