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
	// �ּ� �� ����
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
	
	// ��� ���������� ���� �Ÿ��� ���Ѵ�� �ʱ�ȭ ���ֱ�.
    // �����ǻ��ס�
    // ������ �������� ������ �Ÿ��� �ִ񰪺��� ū ������ �����ؾ� �Ѵ�.
	for (int i = 1; i <= n; i++) dist[i] = 0x7fffffff;

	// �������� ���� ����(Information)�� ��Ͽ� �߰��ϰ�, �Ÿ� �迭(dist)�� �������ش�.
	Q.push({ 0, start });
	dist[start] = 0;
	
	// �Ÿ� �������� ��� ������ ������ �Ÿ� ������ �ݺ��Ѵ�.
	while (!Q.empty()) {
		int cost = Q.top().first;
		int cur = Q.top().second;
		Q.pop();
		
		// ���� ������ �ֽ� ������ �ٸ���, �ǹ̾��� ���� �����̹Ƿ� ����Ѵ�.
		if (dist[cur] != cost) continue;

		// ����� ��� �������� ���ؼ� �ٸ� �����鿡 ���� ������ �������ش�.
		for (int i = 0; i < con[cur].size(); i++) {
			int ncost = con[cur][i].first;
			int nxt = con[cur][i].second;
			if (dist[cur] + ncost >= dist[nxt]) continue;

			// to ���� �� �� �ִ� �� ª�� �Ÿ��� ã�Ҵٸ� �̿� ���� ������ �����ϰ� PQ�� ������ش�.
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
