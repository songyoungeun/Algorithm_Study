#include <iostream>

using namespace std;

int m, k;
int color[51];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m;
	int total = 0; double res = 0;
	for(int i = 0; i < m; i++){
		cin >> color[i];
		total += color[i];
	}
	cin >> k;
	for(int i = 0; i < m; i++){
		double tmp = 1.0;
		if(k > color[i]) continue;
		for(int j = 0; j < k; j++){		
			tmp *= (double)(color[i] - j) / (total - j);
		}
		res += tmp;
	}
	printf("%.9lf",res);
//	cout << fixed;
//	cout.precision(16); //소수점16자리까지  
//	cout << res;
}
