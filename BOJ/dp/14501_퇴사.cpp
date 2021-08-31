#include <iostream>
#include <algorithm>
using namespace std;

int n; // �־��� ��¥
int t[16]; // ����� �Ϸ��ϴµ� �ɸ��� �Ⱓ
int p[16]; // ����� ���� �� ���� �� �ִ� �ݾ�
int d[16]; // �ش� ��¥�� ���� �� �ִ� �ִ� �ݾ�
int ans = 0; // �ִ� ����

int main(){
    //1. ���� �Է�
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }

    // 2. DP ����
    for(int i=1; i<=n; i++){
        // 1) i��° ���� ���� ���� ���
        if(i+t[i] <=n+1){
            d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
            cout << "1: " << i+t[i]<< ' ' << d[i+t[i]] <<'\n';
            // �ִ밪 ����
            ans = max(ans, d[i+t[i]]);
        }

        // 2) i��° ���� ���� ���� �ʾ��� ���
        d[i+1] = max(d[i+1], d[i]);
        cout << "2: " << i+1<< ' ' << d[i+1] <<'\n';
        // �ִ밪 ����
        ans = max(ans, d[i+1]);
        cout << "3: " << ans <<'\n';
    }

    // 3. ���
    printf("%d\n", ans);
}
