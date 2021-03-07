#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x, y;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first < b.first) return true;
	else if(a.first == b.first) return a.second < b.second;
	else return false;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v.push_back({y,x});
	}
	sort(v.begin(),v.end(),cmp);

	for(int i = 0; i < n; i++) 
		cout << v[i].second << ' ' << v[i].first<< '\n';
	
	return 0;
}
