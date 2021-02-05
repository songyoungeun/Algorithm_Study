#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
int city[51][51];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> city[i][j];
			if(city[i][j] == 1) house.push_back({i,j});
			if(city[i][j] == 2) chicken.push_back({i,j}); 
		}
	}
		
	vector<int> brute(chicken.size(),1);
	fill(brute.begin(), brute.begin() + chicken.size() -m,0);
	int mn = 0x7f7f7f7f;
	do{
		int dist = 0;
		for(auto h : house){
			int tmp = 0x7f7f7f7f;
			for(int i = 0; i < chicken.size(); i++){
				if(brute[i] == 0) continue;
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			dist += tmp;
		}
		mn = min(mn, dist);
	} 
	while(next_permutation(brute.begin(), brute.end()));
	cout << mn;
		
} 
