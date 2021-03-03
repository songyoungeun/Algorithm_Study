#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b){
	return a.first < b.first;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,string>> client(n);
	for(int i = 0; i < n; i++)
		cin >> client[i].first >> client[i].second;
		
	stable_sort(client.begin(), client.end(), cmp);
	for(int i = 0; i < n; i++)cout << client[i].first << ' '<< client[i].second << '\n';
}
