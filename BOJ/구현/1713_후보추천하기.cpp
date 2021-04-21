#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int reco[101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<pair<int,int>>v(n); //순서, 사진  
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		reco[num] ++;
		bool change = true;
		for(int j = 0; j < n; j++){
			if(v[j].second == 0){ //사진틀이 비어있는 경우  
				v[j].second = num;
				v[j].first = i;
				change = false;
				break; 
			}
			else if(v[j].second == num){ //이미 후보자의 사진  등록된 경우  
				change = false;
				break;
			}
		}
		if(change){ // 사진틀 비지않고 사진틀에 후보자 없는 경우  
			int idx = 0;
			for(int j = 1; j < n; j++){
				if(reco[v[j].second] == reco[v[idx].second]){ //추천수 낮은거 여러개인 경우  
					if(v[j].first < v[idx].first) 
						idx = j; //먼저 등록된거 삭제  
				}
				else if (reco[v[j].second] < reco[v[idx].second]) {
                    idx = j; //추천수 낮은 순서로  
                }
			
			}
			reco[v[idx].second] = 0; //바꿔치기하면 추천수 초기화 
			v[idx].first = i;
			v[idx].second = num; 
		}
	} 
	vector<int> pict;
	for(int i = 0; i < n; i++){
		pict.push_back(v[i].second);
	}
	sort(pict.begin(),pict.end());
	for(int i = 0; i < n; i++){
		cout << pict[i] << ' ';
	}
}
