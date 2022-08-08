#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    int len = brown / 2 + 2;
	// w * h = brown + yellow 
	// (w-2) * (h-2) = yellow
    int w = len - 3;
    int h = 3; //���̰� 3�̻��̾�� yellow�� ������  

    while(w >= h){
        if(w * h == (brown + yellow)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}

