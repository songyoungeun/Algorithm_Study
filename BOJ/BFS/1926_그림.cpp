#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
int board[502][502]; // 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����
bool vis[502][502]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // �����¿� �� ������ �ǹ�
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j];
  int mx = 0; // �׸��� �ִ�
  int num = 0; // �׸��� ��
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){ // (i, j)�� ���������� �ϰ� ���� ��Ȳ
      if(board[i][j] == 0 or vis[i][j]) continue; // �ش� ĭ�� ��ĥ�� �ȵ� �κ�(0)�̰ų� �̹� (i, j)�� �湮���� ��� �Ѿ
      // (i,j)�� ���ο� �׸��� �����ִ� ������
      num++; // �׸��� �� 1 ����
      queue<pair<int,int> > Q;
      vis[i][j] = 1; // (i,j)�� BFS�� �����ϱ� ���� �غ�
      Q.push({i,j});
      int area = 0; // �׸��� ����
      while(!Q.empty()){
        area++; // ť�� ����ִ� ���Ҹ� �ϳ� �� �� ���� ���̸� 1 ������Ŵ
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ // �����¿� ĭ�� ���캼 ���̴�.
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // ���� ���� ��� �Ѿ
          if(vis[nx][ny] || board[nx][ny] != 1) continue; // �̹� �湮�� ĭ�̰ų� �Ķ� ĭ�� �ƴ� ���
          vis[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
          Q.push({nx,ny});
        }
      }
      // (i, j)�� ���������� �ϴ� BFS�� �����
      mx = max(mx, area); // area�� mx���� Ŭ ��� mx�� area�� ����. max�� STL�� ���ǵ� �Լ�
    }
  }
  cout << num << '\n' << mx;
}
