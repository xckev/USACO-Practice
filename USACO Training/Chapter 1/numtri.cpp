/*
ID: xckevin1
LANG: C++
TASK: numtri
*/

//category: DFS

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int r, best;
vector<vector<int>> v;

void solve(int e, int col, int sum){
    if(e == r){
        best = max(sum, best);
    }
    else if(e == 0){
        solve(e+1, col, v[0][0]);
    }
    else{
        int samecol = v[e][col];
        sum += samecol;
        solve(e+1, col, sum);
        sum -= samecol;

        int diffcol = v[e][col+1];
        sum += diffcol;
        solve(e+1, col+1, sum);
        sum -= diffcol;
    }
}

int main(){
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");

    fin >> r;
    best = 0;

    for(int i = 1; i <= r; i++){
        vector<int> row;
        for(int j = 0; j < i; j++){
            int e;
            fin >> e;
            row.push_back(e);
        }
        v.push_back(row);
    }

    solve(0, 0, 0);

    fout << best << endl;

}