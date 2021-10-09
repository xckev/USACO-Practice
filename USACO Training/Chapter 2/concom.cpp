/*
ID: xckevin1
LANG: C++
TASK: concom
*/

//complete search 

#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int n;
vector<pair<int, int>> owners[101];
int owns[101];
bool isowned[101];

void solve(int i){
    if(isowned[i]){
        return;
    }

    isowned[i] = true;
    for(pair<int, int> p : owners[i]){
        owns[p.first] += p.second;
        if(owns[p.first] > 50){
            solve(p.first);
        }
    }
}

int main(){
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");

    fin >> n;
    for(int i = 0; i < n; ++i){
        int x, y, percent;
        fin >> x >> y >> percent;
        owners[x].push_back({y, percent});
    }

    for(int i = 1; i <= 100; ++i){
        fill(owns, owns+101, 0);
        fill(isowned, isowned+101, 0);
        solve(i);
        for(int j = 1; j <= 100; ++j){
            if(i != j && isowned[j]){
                fout << i << " " << j << endl;
            }
        }
    }
}