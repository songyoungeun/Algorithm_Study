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
	vector<pair<int,int>>v(n); //����, ����  
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		reco[num] ++;
		bool change = true;
		for(int j = 0; j < n; j++){
			if(v[j].second == 0){ //����Ʋ�� ����ִ� ���  
				v[j].second = num;
				v[j].first = i;
				change = false;
				break; 
			}
			else if(v[j].second == num){ //�̹� �ĺ����� ����  ��ϵ� ���  
				change = false;
				break;
			}
		}
		if(change){ // ����Ʋ �����ʰ� ����Ʋ�� �ĺ��� ���� ���  
			int idx = 0;
			for(int j = 1; j < n; j++){
				if(reco[v[j].second] == reco[v[idx].second]){ //��õ�� ������ �������� ���  
					if(v[j].first < v[idx].first) 
						idx = j; //���� ��ϵȰ� ����  
				}
				else if (reco[v[j].second] < reco[v[idx].second]) {
                    idx = j; //��õ�� ���� ������  
                }
			
			}
			reco[v[idx].second] = 0; //�ٲ�ġ���ϸ� ��õ�� �ʱ�ȭ 
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
