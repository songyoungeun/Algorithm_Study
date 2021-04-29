#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int>v;
int arr[8];
bool isused[8];

void func(int k, int idx){ 
	if(k == m){ 
	    for(int i = 0; i < m; i++){
		    cout << arr[i] << ' '; 	
		}
	    cout << '\n';
	    return;
  	}
	int before = 0;
	
	for(int i = idx; i < n; i++){ 
	    if(!isused[i] and before != v[i]){
	      	before = v[i];
	      	arr[k] = v[i]; 
	      	isused[i] = 1; 
	      	func(k+1,i+1);
	      	isused[i] = 0;
	    }
	}
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int val;
  for(int i = 0; i < n; i++){
  	cin >> val;
  	v.push_back(val);
  }
  sort(v.begin(),v.end());
  func(0,0);
}
