/*
ID: xckevin1
LANG: C++
TASK: barn1
*/

//Greedy: take the m-1 largest gaps

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int m, s, c;
    fin >> m >> s >> c;

    vector<int> occ;
    for(int i = 0; i < c; i++){
        int add;
        fin >> add;
        occ.push_back(add);
        //cout << "added: " << add << endl;
    }
    sort(occ.begin(), occ.end());

    vector<int> gaps;
    int prev = occ[0];
    for(int i = 1; i < occ.size(); i++){
        int curr = occ[i];
        int gap = curr - prev -1;
        gaps.push_back(gap);
        //cout << "curr: " << curr << "  prev: " << prev << "  gap size: " << gap << endl;
        prev = curr;
    }

    sort(gaps.rbegin(), gaps.rend());

    //cout << "gaps length: " << gaps.size() << ", m: " << m << endl;
    int total = 0;
    int siz = gaps.size();
    int lim = min(siz, m-1);
    for(int i = 0; i < lim; i++){
        //cout << "gap chosen: " << gaps[i] << endl;
        total += gaps[i];
    }

    s-= (occ[0]-1) + (s - occ[occ.size()-1]);

    fout << s - total << endl;
}