#include <iostream>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int k){ // ���� k������ ���� ������.
  if(k == m){ // m���� ��� ��������
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' '; // arr�� ����ص� ���� ���
    cout << '\n';
//    cout << "**" << '\n';
    return;
  }

  for(int i = 1; i <= n; i++){ // 1���� n������ ���� ����
//    cout << "#####" << '\n';
    if(!isused[i]){ // ���� i�� ������ �ʾ�����
//      cout<< '@' << k << i << '\n';
      arr[k] = i; // k��° ���� i�� ����
      isused[i] = 1; // i�� ���Ǿ��ٰ� ǥ��
      func(k+1); // ���� ���� ���Ϸ� �� �ܰ� �� ��
      isused[i] = 0; // k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�������� i�� ���� �������ʾҴٰ� �����.
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}
