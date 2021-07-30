#include <iostream>
#include <algorithm>
#include <vector>

int dice[7];

using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i < 3; i++){
		int num;
		cin >> num;
		dice[num]++;
	}
	int res = 0;
	int mxnum = -1;
	for(int i = 0; i < 7; i++){
		if(dice[i] == 3){
			res = 10000 + i *1000;
			break;
		}
		else if(dice[i] == 2){
			res = 1000 + i *100;
			break;
		}
		else if(dice[i] == 1){
			mxnum = max(mxnum, i);
		}
	} 
	if(res){
		cout << res;
	}
	else{
		cout << mxnum * 100;
	}
}

//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	vector<int> v(3);
//	cin >> v[0] >> v[1] >> v[2];
//	sort(v.begin(),v.end());
//
//	if(v[0] == v[1] && v[1] == v[2]){
//		cout << 10000 + (v[0] * 1000);
//	}
//	else if(v[0] == v[1]){
//		cout << 1000 + (v[0] * 100);
//	}
//	else if(v[0] == v[2]){
//		cout << 1000 + (v[0] * 100);
//	}
//	else if(v[1] == v[2]){
//		cout << 1000 + (v[0] * 100);
//	}
//	else{
//		cout << v[2] * 100;
//	}
//}
