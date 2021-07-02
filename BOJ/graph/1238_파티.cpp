#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int res[1001];
int dist[1001];
vector<pair<int,int>> map[1001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> PQ;
    dist[start] = 0;
    PQ.push({0, start});
 
    while (!PQ.empty())
    {
        int cost = -PQ.top().first;
        int here = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < map[here].size(); i++)
        {
            int nxt = map[here][i].first;
            int ncost = map[here][i].second;
 
            if (dist[nxt] > cost + ncost)
            {
                dist[nxt] = cost + ncost;
                PQ.push({-dist[nxt], nxt});
            }
        }
    }
 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m >> x;

	for(int i = 0; i < m; i++){
		int s, e, c;
		cin >> s >> e >> c;
		map[s].push_back({e,c});
	}
	
	
	for(int i = 1; i <= n; i++){
		fill(dist,dist+n+1,INF);
		dijkstra(i);
		res[i] = dist[x];
	}
	fill(dist,dist+n+1,INF);
	dijkstra(x);
	for(int i = 1; i <= n; i++){
		res[i] += dist[i];
	}

	int ans;
	ans = *max_element(res+1, res+n+1);
	cout << ans;
}
