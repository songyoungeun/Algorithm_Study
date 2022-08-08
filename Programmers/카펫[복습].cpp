#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    int len = brown / 2 + 2;
	// w * h = brown + yellow 
	// (w-2) * (h-2) = yellow
    int w = len - 3;
    int h = 3; //높이가 3이상이어야 yellow가 존재함  

    while(w >= h){
        if(w * h == (brown + yellow)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}

