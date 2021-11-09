/*
ID: xckevin1
LANG: C++
TASK: inflate
*/

//dynamic prog (WORKS!)

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int m, n;
int storage[10001];

int main(){
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    fin >> m >> n;
    storage[0] = 0;

    for(int i = 0; i < n; i++){
        int p, l;
        fin >> p >> l;
        for(int j = l; j <= m; j++){
            storage[j] = max(storage[j], storage[j-l] + p);
        }
    }
    int result = 0;
    for(int i = 0; i <= m; i++){
        result = max(result, storage[i]);
    }

    fout << result << endl;
}