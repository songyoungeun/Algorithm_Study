#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int len = words.size();
    map<string,int> h;
    h[words[0]]=1;
    for(int i=1;i<len;i++)
    {
        int len1=words[i-1].size();
        if(h[words[i]] || (words[i-1][len1-1]!=words[i][0]))
        	//�̹� ���� �ܾ�ų� ���ڳ� != ����ù 
            return {i%n+1,i/n+1};
        else
            h[words[i]]=1;
    }
    return {0,0};
    
    
//    unordered_set<string> said_words;                       //O(1)���� ���� �ܾ����� üũ�� �� �ִ� �����̳�
//    for(int i=0; i<words.size(); ++i)
//        if(!said_words.insert(words[i]).second ||           //�̹� ���� �ܾ��̰ų�
//           (i>0 && words[i-1].back() != words[i].front()))  //�տ��� ���� �ܾ��� ������ �������� ���� ��
//            return {i%n+1,i/n+1};                           //Ż���ڹ�ȣ�� Ż���ڰ� ���°�� ���� �ܾ����� ��ȯ
//    return {0,0};                                           //������ Ż���� �߻� ���� ���
}
