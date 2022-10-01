#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
	
    //���ڼ����� ������ �ƴ� ���������� ���ĵ�
//     sort(phone_book.begin(), phone_book.end()); 
    
//     for(int i = 0; i < phone_book.size() - 1; i++){
//         if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].size()))
//             return false;
//     }
//     return true;

    //hash��� -> unordered_map�� ����� �ؽ� ���
    unordered_map<string,int> hash_map;
    for(int i = 0; i < phone_book.size(); i++){
        hash_map[phone_book[i]] = 1;
    }

    for(int i = 0; i < phone_book.size(); i++){
        string phone_number = "";
        for(int j=0; j<phone_book[i].length()-1;j++){ //���ξ�ϱ� ������ ��
            
        // for(int j = 0; j < phone_book[i].size(); j++){
            phone_number += phone_book[i][j];
            if(hash_map[phone_number]) return false;
            // if(hash_map[phone_number] && phone_number != phone_book[i]) return false;
        }
    }
    return true;
}
