#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> coord;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first < b.first) return a.first < b.first;
	else if(a.first == b.first) return a.second < b.second;
	else return false;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	coord.resize(n);
	for(int i = 0; i < n; i++)
		cin >> coord[i].first >> coord[i].second;
	sort(coord.begin(),coord.end(),cmp);
	for(int i = 0; i < n; i++) cout << coord[i].first << ' ' << coord[i].second << '\n';
}

