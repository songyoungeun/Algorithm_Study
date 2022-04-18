#include<iostream>
#include<algorithm>

using namespace std;

int l, c, selected[16];
char arr[16];

void input(){
	cin >> l >> c;
	for(int i = 1; i <= c; i++){
		cin >> arr[i];
	}
}
bool isVowel(char x){
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' ||x == 'u';
}
void rec_func(int k){
	if(k == l + 1){
		int vowel = 0, consonant = 0;
		for(int i = 1; i <= l; i++){
			if(isVowel(arr[selected[i]])) vowel++;
			else consonant++;
 		}
 		if(vowel >= 1 && consonant >= 2){
 			for(int i = 1; i <= l; i++)
 				cout << arr[selected[i]];
 			cout << '\n';
		}
		return;
	}
	for(int cand = selected[k - 1] + 1; cand <= c; cand++){
		selected[k] = cand;
		rec_func(k + 1);
		selected[k] = 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	sort(arr + 1, arr + 1 + c);
	rec_func(1);
}
