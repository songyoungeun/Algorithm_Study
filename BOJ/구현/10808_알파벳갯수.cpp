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
    freq[c-'a']++; //c가 a면 a-a =0번째에  에 1이 저장됨 
  for(int i = 0; i < 26; i++) // a~z가 아스키코드로 0~25 
    cout << freq[i] << ' ';
}

//int main(void) {
//  ios::sync_with_stdio(0);
//  cin.tie(0);
//  string s;
//  cin >> s;
//  for(char a = 'a'; a <= 'z'; a++){ //이건 알파벳 전부를 돌아 불필요해 
//    int cnt = 0;
//    for(auto c : s)
//      if(a == c) cnt++;
//    cout << cnt << ' ';
//  }
//}
