#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define NM 1005


int n, m, start, destination, dist[NM];
vector<pair<int,int>> con[NM];


void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		con[from].push_back({ weight, to });
	}
	cin >> start >> destination;
}

#include <queue>
void pro() {
	// 최소 힙 생성
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
	
	// 모든 정점까지에 대한 거리를 무한대로 초기화 해주기.
    // ※주의사항※
    // 문제의 정답으로 가능한 거리의 최댓값보다 큰 값임을 보장해야 한다.
	for (int i = 1; i <= n; i++) dist[i] = 0x7fffffff;

	// 시작점에 대한 정보(Information)을 기록에 추가하고, 거리 배열(dist)에 갱신해준다.
	Q.push({ 0, start });
	dist[start] = 0;
	
	// 거리 정보들이 모두 소진될 때까지 거리 갱신을 반복한다.
	while (!Q.empty()) {
		int cost = Q.top().first;
		int cur = Q.top().second;
		Q.pop();
		
		// 꺼낸 정보가 최신 정보랑 다르면, 의미없이 낡은 정보이므로 폐기한다.
		if (dist[cur] != cost) continue;

		// 연결된 모든 간선들을 통해서 다른 정점들에 대한 정보를 갱신해준다.
		for (int i = 0; i < con[cur].size(); i++) {
			int ncost = con[cur][i].first;
			int nxt = con[cur][i].second;
			if (dist[cur] + ncost >= dist[nxt]) continue;

			// to 까지 갈 수 있는 더 짧은 거리를 찾았다면 이에 대한 정보를 갱신하고 PQ에 기록해준다.
			dist[nxt] = dist[cur] + ncost;
			Q.push({ dist[nxt],nxt });
		}
	}
	cout << dist[destination];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	pro();
	return 0;
}
