#include <iostream>
#include <string>
using namespace std;

int freq[26];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for(auto c : s) 
    freq[c-'a']++; //c�� a�� a-a =0��°��  �� 1�� ����� 
  for(int i = 0; i < 26; i++) // a~z�� �ƽ�Ű�ڵ�� 0~25 
    cout << freq[i] << ' ';
}

//int main(void) {
//  ios::sync_with_stdio(0);
//  cin.tie(0);
//  string s;
//  cin >> s;
//  for(char a = 'a'; a <= 'z'; a++){ //�̰� ���ĺ� ���θ� ���� ���ʿ��� 
//    int cnt = 0;
//    for(auto c : s)
//      if(a == c) cnt++;
//    cout << cnt << ' ';
//  }
//}
