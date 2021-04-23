#include <iostream>

using namespace std;

long long x,y;
int z;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> y;
	z = y*100 / x;
	if(z >= 99){
		cout << -1;
	}
	else{
		int left = 0, right = 1000000000;
		int mid, tmpZ;
		while(left <= right){
			mid = (left + right) / 2;
			tmpZ = (y+mid) *100 / (x+mid);
			if(z < tmpZ){
				right = mid -1;
			} 
			else{
				left = mid +1;
			}
		}
		cout << left;
	}
}
